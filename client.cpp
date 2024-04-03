#include <zmq.hpp>
#include "generated/event.pb.h"
#include "utils.h"
//
#include <fmt/core.h>
#include <azmq/signal.hpp>
#include <boost/asio/io_service.hpp>
#include <chrono>

using namespace std::chrono;

static int PORT = 5000;
static int REQUESTS = 100000;

int main()
{
    /*
    boost::asio::io_service ios;
    azmq::pair_socket sb(ios);
    azmq::pair_socket sc(ios);

    sb.bind("inproc://test");
    sc.connect("inproc://test");

    azmq::signal::send(sb, 65);
    std::cout << "Received: " << azmq::signal::wait(sc) << std::endl;
    */

    zmq::context_t context(1);

    zmq::socket_t socket(context, zmq::socket_type::dealer);
    s_set_id(socket);
    fmt::println("socket id: {}", socket.get(zmq::sockopt::routing_id));

    socket.connect(fmt::format("tcp://localhost:{}", PORT));

    // timeout
    socket.set(zmq::sockopt::linger, 1000);
    // disable socket queue (use last value received)
    // socket.set(zmq::sockopt::conflate, 1);
    // size send buffers (kernel limits)
    socket.set(zmq::sockopt::sndbuf, 2000000);
    // size receive buffers (kernel limits)
    socket.set(zmq::sockopt::rcvbuf, 2000000);
    // size send buffers
    socket.set(zmq::sockopt::sndhwm, 2000000);
    // size receive buffers
    socket.set(zmq::sockopt::rcvhwm, 2000000);

    // multi process
    // socket.connect("ipc://noname");

    // multi thread
    // socket.connect("inproc://noname");

    fmt::print("Client connected to {}.\n", PORT);

    auto begin = high_resolution_clock::now();

    for(int i = 0; i < REQUESTS; i++) {

        zeromq_project::proto::Mutation mutation;
        mutation.set_id(i);
        mutation.set_name("job_name");
        mutation.set_origin("myorigin");
        mutation.set_destination("calculate2");
        mutation.set_year(2024);
        mutation.set_year2(2025);
        mutation.set_age(i);

        // send Mutation
        // s_sendmore(socket, std::string(""));
        protomq::send_message(socket, mutation);
    }

    std::vector<zeromq_project::proto::Response> responses;
    protomq::recv_message_all(socket, responses, REQUESTS);
    /*
    int i = 0;
    for(const auto& response : responses)
    {
        fmt::print("Received message {}: {}\n", i, response.DebugString());
        ++i;
    }
    */

    auto elapsed = high_resolution_clock::now() - begin;
    auto elapsed_ms = duration_cast<milliseconds>(elapsed).count();

    fmt::print("OK, received: {}, expected: {}, speed: {:.2f} reqs/seg.\n", responses.size(), REQUESTS, responses.size() / (elapsed_ms / 1000.0));
    fmt::print("Elapsed time: {} ms\n", elapsed_ms);

    return 0;
}
