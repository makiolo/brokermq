
//  Least-recently used (LRU) queue device
//  Clients and workers are shown here in-process
//

#include "zhelpers.hpp"
#include <thread>
#include <queue>
#include <fmt/core.h>

//  Basic request-reply client using REQ socket
//
void receive_empty_message(zmq::socket_t& sock)
{
    std::string empty = s_recv(sock);
    assert(empty.size() == 0);
}

void client_thread(int id) {
    zmq::context_t context(1);
    zmq::socket_t client(context, ZMQ_REQ);

#if (defined (WIN32))
    s_set_id(client, id);
    client.connect("tcp://localhost:5001"); // frontend
#else
    s_set_id(client); // Set a printable identity
    client.connect("ipc://frontend.ipc");
#endif

    //  Send request, get reply
    s_send(client, std::string("HELLO"));
    std::string reply = s_recv(client);
    std::cout << "Client: " << reply << std::endl;
    return;
}

//  Worker using REQ socket to do LRU routing
//
void worker_thread(int id) {
    zmq::context_t context(1);
    zmq::socket_t worker(context, ZMQ_REQ);

    s_set_id(worker);
    worker.connect("tcp://localhost:5000"); // backend

    //  Tell backend we're ready for work
    s_send(worker, std::string("READY"));

    while (1) {
        //  Read and save all frames until we get an empty frame
        //  In this example there is only 1 but it could be more
        std::string address = s_recv(worker);
        receive_empty_message(worker);
        //  Get request, send reply
        std::string request = s_recv(worker);
        std::cout << "Worker: " << request << std::endl;

        s_sendmore(worker, address);
        s_sendmore(worker, std::string(""));
        s_send(worker, std::string("OK"));
    }
    return;
}



int main(int argc, char *argv[])
{
    //  Prepare our context and sockets
    zmq::context_t context(1);
    zmq::socket_t frontend(context, ZMQ_DEALER);
    zmq::socket_t backend(context, ZMQ_DEALER);

    s_set_id(frontend);
    s_set_id(backend);

    frontend.bind("tcp://*:5000"); // frontend
    backend.bind("tcp://*:5001"); // backend

    fmt::println("backend id: {}", backend.get(zmq::sockopt::routing_id));
    fmt::println("frontend id: {}", frontend.get(zmq::sockopt::routing_id));

    fmt::print("Broker LRU started in 5000 & 5001.\n");

    //  Logic of LRU loop
    //  - Poll backend always, frontend only if 1 or >1 worker ready
    //  - If worker replies, queue worker as ready and forward reply
    //    to client if necessary
    //  - If client requests, pop next worker and send request to it
    //
    //  A very simple queue structure with known max size
    std::queue<std::string> worker_queue;

    while (1) {

        //  Initialize poll set
        zmq::pollitem_t items[] = {
                //  Always poll for worker activity on backend
                { backend, 0, ZMQ_POLLIN, 0 },
                //  Poll front-end only if we have available workers
                { frontend, 0, ZMQ_POLLIN, 0 }
        };
        if (!worker_queue.empty())
            zmq::poll(&items[0], 2, -1);
        else
            zmq::poll(&items[0], 1, -1);

        //  receive replies from workers
        if (items[0].revents & ZMQ_POLLIN) {

            //  Queue worker address for LRU routing
            auto backend_id = backend.get(zmq::sockopt::routing_id);
            worker_queue.push(backend_id);

            //  Third frame is READY or else a client reply address
            std::string client_addr = s_recv(backend);

            //  If client reply, send rest back to frontend
            if (client_addr.compare("READY") != 0) {
                receive_empty_message(backend);
                std::string reply = s_recv(backend);
                s_sendmore(frontend, client_addr);
                s_sendmore(frontend, std::string(""));
                s_send(frontend, reply);
            }
        }
        if (items[1].revents & ZMQ_POLLIN) {

            std::string request = s_recv(frontend);

            std::string worker_addr = worker_queue.front();
            worker_queue.pop();

            auto frontend_id = backend.get(zmq::sockopt::routing_id);
            s_sendmore(backend, frontend_id);
            s_sendmore(backend, std::string(""));
            s_send(backend, request);
        }
    }
    return 0;
}

