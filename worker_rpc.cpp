#include <iostream>
#include <zmq.hpp>
#include "generated/event.pb.h"
#include "utils.h"
#include <fmt/core.h>
#include "rpc.h"
#include <functional>
#include <map>

int main()
{
    srand(time(NULL));

    using func_factory = zeromq_project::proto::Response(const zeromq_project::proto::Mutation&);
    std::map<std::string, std::function<func_factory> > factories;
    factories["calculate1"] = std::bind(protomq::calculate1, std::placeholders::_1);
    factories["calculate2"] = std::bind(protomq::calculate2, std::placeholders::_1);

    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::dealer);

    s_set_id(socket, "server-end");

    fmt::println("socket id: {}", socket.get(zmq::sockopt::routing_id));

    // El servidor pertenece a un Broker RPC
    socket.connect("tcp://localhost:5003");


    socket.set(zmq::sockopt::sndbuf, 2000000);
    socket.set(zmq::sockopt::rcvbuf, 2000000);
    socket.set(zmq::sockopt::sndhwm, 2000000);
    socket.set(zmq::sockopt::rcvhwm, 2000000);

    // multi process
    // socket.connect("ipc://backend.ipc");

    // multi thread
    // socket.connect("inproc://noname");

    fmt::print("Worker connected to 5003.\n");

    while(true)
    {
        // recv Mutation
        zeromq_project::proto::Mutation mutation;
        protomq::recv_message(socket, mutation);

        fmt::println("Received proto {}.", mutation.ticket_id());

        // send Response
        auto func = factories.at(mutation.destination() );
        auto response = func(mutation);

        fmt::println("Send response proto {}.", response.ticket_id());

        protomq::send_message(socket, response);
    }

    return 0;
}
