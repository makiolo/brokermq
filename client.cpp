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
static int REQUESTS = 100;

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

    zmq::socket_t socket(context, zmq::socket_type::req);

    s_set_id(socket, "client-start");
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

    fmt::print("Client connected to {}.\n", PORT);

    auto begin = high_resolution_clock::now();

    for(int i = 0; i < REQUESTS; i++) {

        // envias la request
        // recibes el aviso (cambio estado PENDING to ACCEPTED) (el balancer mira si hay recursos suficientes)
        // recibes el aviso (cambio de estado de ACCEPTED to DONE) (el broker rpc y sus workers han ejecutado la request)
        // recibes la response

        zeromq_project::proto::Mutation mutation;
        mutation.set_ticket_id(i);
        mutation.set_id(i);
        mutation.set_name("job_name");
        mutation.set_origin("myorigin");
        if(i == 0)
            mutation.set_destination("calculate1");
        else
            mutation.set_destination("calculate2");
        mutation.set_year(2024);
        mutation.set_year2(2025);
        mutation.set_age(i);

        // send Mutation
        protomq::send_message(socket, mutation);
        fmt::println("send ticket id {}.", i);

        // recv response
        zeromq_project::proto::Response response;
        protomq::recv_message(socket, response);
        fmt::println("response {}.", response.DebugString());
        std::string output_str;
        protomq::message_to_json(response, output_str);
        fmt::println("response json {}.", output_str);
    }

    auto elapsed = high_resolution_clock::now() - begin;
    auto elapsed_ms = duration_cast<milliseconds>(elapsed).count();

    // fmt::print("OK, received: {}, expected: {}, speed: {:.2f} reqs/seg.\n", responses.size(), REQUESTS, responses.size() / (elapsed_ms / 1000.0));
    fmt::print("Elapsed time: {} ms\n", elapsed_ms);

    return 0;
}
