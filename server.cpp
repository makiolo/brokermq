#include <iostream>
#include <zmq.hpp>
#include "generated/event.pb.h"
#include "utils.h"

int main()
{
    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::rep);

    // multi machine
    socket.connect("tcp://localhost:5560");

    // multi process
    // socket.connect("ipc://noname");

    // multi thread
    // socket.connect("inproc://noname");

    std::cout << "Server started" << std::endl;

    for(;;)
    {
        // Los servers no pueden pedir cosas a los clientes
        // son pasivos, esperan a que les llegue algo

        // recv Mutation
        zeromq_project::proto::Mutation mutation;
        protomq::recv_message(&socket, mutation);

        std::string data;
        protomq::message_to_json(mutation, data);
        std::cout << "Register mutation in json: " << data << std::endl;

        // send Response
        zeromq_project::proto::Response response;
        switch(mutation.id())
        {
            case 1:
                std::cout << "mutation id = 1" << std::endl;
                response.set_code(200);
                break;
            case 2:
                std::cout << "mutation id = 2" << std::endl;
                response.set_code(200);
                break;
            default:
                std::cout << "default id = " << mutation.id() << std::endl;
                response.set_code(404);
                break;
        }
        protomq::send_message(&socket, response);
    }

    return 0;
}
