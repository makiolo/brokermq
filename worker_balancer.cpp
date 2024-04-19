#include <zmq.hpp>
#include "utils.h"
#include "rpc.h"
#include <fmt/core.h>
#include <functional>
#include <map>

int main()
{
    srand(time(NULL));

    zmq::context_t context(1);
    zmq::socket_t frontend(context, zmq::socket_type::dealer);
    zmq::socket_t backend(context, zmq::socket_type::dealer);

    s_set_id(frontend, "worker-balancer-frontend");
    s_set_id(backend, "worker-balancer-backend");

    fmt::println("frontend id: {}", frontend.get(zmq::sockopt::routing_id));
    fmt::println("backend id: {}", backend.get(zmq::sockopt::routing_id));

    frontend.connect("tcp://localhost:5001");
    backend.connect("tcp://localhost:5002");

    fmt::println("frontend connected to 5001 & 5002.");

    //  Tell backend we're ready for work
    s_send(frontend, std::string("READY"));

    while (true)
    {
        // si el frontend tiene cola de tamaño 10
        // recibe 10 mensajes y envia 10 mensajes y recibe 10 respuestas y envia 10 respuestas

        int total = 0;
        const int max_batch = 1;
        std::vector<std::string> client_addresses;
        while(total < max_batch)
        {
            // get header + Request
            client_addresses.emplace_back( s_recv(frontend) );
            receive_empty_message(frontend);
            zeromq_project::proto::Mutation mutation;
            protomq::recv_message(frontend, mutation, true);

            // RPC to frontend
            protomq::send_message(backend, mutation);

            /*
            // more in socket ?
            int more = frontend.get(zmq::sockopt::rcvmore);
            if (!more)
                break;
            else
            */

            ++total;
        }

        // recv in same order to requests ?

        for(int i=0; i < total; ++i)
        {
            zeromq_project::proto::Response response;
            protomq::recv_message(backend, response);

            // send Header + Response (implicit READY)
            s_sendmore(frontend, client_addresses[i]);
            s_sendmore(frontend, std::string(""));
            fmt::println("sent ticket id {}.", response.ticket_id());
            protomq::send_message(frontend, response);
        }
    }
    return 0;
}
