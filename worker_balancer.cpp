#include <zmq.hpp>
#include "utils.h"
#include "rpc.h"
#include <fmt/core.h>
#include <functional>
#include <map>
#include <fmt/core.h>

//
// Created by ricardo on 3/10/24.
//
int main() {

    zmq::context_t context(1);
    zmq::socket_t worker(context, zmq::socket_type::dealer);
    zmq::socket_t backend(context, zmq::socket_type::dealer);

    s_set_id(worker);
    s_set_id(backend);

    fmt::println("worker id: {}", worker.get(zmq::sockopt::routing_id));
    fmt::println("backend id: {}", backend.get(zmq::sockopt::routing_id));

    worker.connect("tcp://localhost:5001"); // backend
    backend.connect("tcp://localhost:5002"); // frontend

    fmt::print("Worker connected to 5001 & 5002.\n");

    while (true) {

        //  Tell backend we're ready for work
        s_send(worker, std::string("READY"));

        // get header + Request
        std::string address = s_recv(worker);
        receive_empty_message(worker);
        zeromq_project::proto::Mutation mutation;
        protomq::recv_message(worker, mutation);
        // fmt::println("received message: {}", mutation.DebugString());

        // RPC to frontend
        // fmt::println("send ... {}", mutation.DebugString());
        protomq::send_message(backend, mutation);
        // fmt::println("sent.");

        zeromq_project::proto::Response response;
        // fmt::println("recv ...");
        protomq::recv_message(backend, response);
        // fmt::println("recv. Forward to RPC. message: {}", response.DebugString());

        // send Header + Response
        s_sendmore(worker, address);
        s_sendmore(worker, std::string(""));
        protomq::send_message(worker, response);
        // fmt::println("send response to parent");

        // fmt::println(".");
    }
    return 0;
}
