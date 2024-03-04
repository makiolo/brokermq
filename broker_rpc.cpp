//
//  Simple request-reply broker in C++
//

#include "zhelpers.hpp"


int main (int argc, char *argv[])
{
    zmq::context_t context(1);
    // clients
    zmq::socket_t frontend (context, ZMQ_ROUTER);
    // workers
    zmq::socket_t backend (context, ZMQ_DEALER);

    frontend.bind("tcp://*:5559");
    backend.bind("tcp://*:5560");

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
            while (1) {
                //  Process all parts of the message
                frontend.recv(message, zmq::recv_flags::none); // new syntax
                size_t more_size = sizeof (more);

                more = frontend.get(zmq::sockopt::rcvmore); // new syntax
                backend.send(message, more? zmq::send_flags::sndmore : zmq::send_flags::none);

                if (!more)
                    break;      //  Last message part
            }
        }
        if (items [1].revents & ZMQ_POLLIN) {
            while (1) {
                //  Process all parts of the message
                backend.recv(message, zmq::recv_flags::none);
                size_t more_size = sizeof (more);

                more = backend.get(zmq::sockopt::rcvmore); // new syntax
                frontend.send(message, more? zmq::send_flags::sndmore : zmq::send_flags::none);

                if (!more)
                    break;      //  Last message part
            }
        }
    }
    return 0;
}
