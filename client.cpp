#include <iostream>
#include <zmq.hpp>
#include "generated/event.pb.h"
#include "utils.h"

int main() {

    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::req);

    // multi machine
    socket.connect("tcp://localhost:5559");

    // multi process
    // socket.connect("ipc://noname");

    // multi thread
    // socket.connect("inproc://noname");

    for(;;) {

        // send Mutation
        zeromq_project::proto::Mutation mutation;
        mutation.set_id(1);
        mutation.set_name("job_name");
        mutation.set_origin("myorigin");
        protomq::send_message(&socket, mutation);

        // recv Response
        zeromq_project::proto::Response response;
        protomq::recv_message(&socket, response);
        std::cout << "Received code " << response.code() << std::endl;
    }

    return 0;
}
