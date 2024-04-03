//
//  Simple request-reply broker in C++
//

#include "zhelpers.hpp"
#include <fmt/core.h>


int main (int argc, char *argv[])
{
    zmq::context_t context(1);
    // clients
    zmq::socket_t frontend (context, ZMQ_DEALER);
    // workers
    zmq::socket_t backend (context, ZMQ_DEALER);

    // El broker RPC pertenece a un Load Balancer (como elegirlo?)
    frontend.bind("tcp://*:5002");
    backend.bind("tcp://*:5003");
    // backend.bind("ipc://backend.ipc");

    frontend.set(zmq::sockopt::sndbuf, 2000000);
    frontend.set(zmq::sockopt::rcvbuf, 2000000);
    frontend.set(zmq::sockopt::sndhwm, 2000000);
    frontend.set(zmq::sockopt::rcvhwm, 2000000);
    backend.set(zmq::sockopt::sndbuf, 2000000);
    backend.set(zmq::sockopt::rcvbuf, 2000000);
    backend.set(zmq::sockopt::sndhwm, 2000000);
    backend.set(zmq::sockopt::rcvhwm, 2000000);

    fmt::print("Broker RPC started in 5002 & 5003.\n");

    zmq::pollitem_t items [] = {
            { frontend, 0, ZMQ_POLLIN, 0 },
            { backend, 0, ZMQ_POLLIN, 0 }
    };

    //  Switch messages between sockets
    while (1) {
        zmq::message_t message;
        int more;               //  Multipart detection

        zmq::poll (&items [0], 2, -1);

        if (items [0].revents & ZMQ_POLLIN) {

            // fmt::print("Frontend activity\n");

            while (1) {
                //  Process all parts of the message
                frontend.recv(message, zmq::recv_flags::none); // new syntax

                // std::string message_str = std::string(static_cast<char*>(message.data()), message.size());;
                // fmt::print("message frontend: {}\n", message_str);

                more = frontend.get(zmq::sockopt::rcvmore); // new syntax
                backend.send(message, more? zmq::send_flags::sndmore : zmq::send_flags::none);

                if (!more)
                    break;      //  Last message part
            }
        }
        if (items [1].revents & ZMQ_POLLIN) {

            // fmt::print("Backend activity\n");

            while (true) {
                //  Process all parts of the message
                backend.recv(message, zmq::recv_flags::none);

                // std::string message_str = std::string(static_cast<char*>(message.data()), message.size());;
                // fmt::print("message backend: {}\n", message_str);

                more = backend.get(zmq::sockopt::rcvmore); // new syntax
                frontend.send(message, more? zmq::send_flags::sndmore : zmq::send_flags::none);

                if (!more)
                    break;      //  Last message part
            }
        }
    }
    return 0;
}
