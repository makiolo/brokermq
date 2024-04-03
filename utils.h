//
// Created by ricardo on 3/4/24.
//

#ifndef ZEROMQ_PROJECT_UTILS_H
#define ZEROMQ_PROJECT_UTILS_H

#include <google/protobuf/util/json_util.h>
#include <fmt/core.h>
#include <zmq_addon.hpp>
#include "generated/event.pb.h"
#include "zhelpers.hpp"

//  Basic request-reply client using REQ socket
//
void receive_empty_message(zmq::socket_t& sock)
{
    std::string empty = s_recv(sock);
    assert(empty.size() == 0);
}

namespace protomq {

void send_message(zmq::socket_t& socket, const google::protobuf::Message &message, bool more = false, bool wait = false) {
    std::string str;
    message.SerializeToString(&str);

    // TODO: al crear el buffer, se copia el string, se puede evitar?

    socket.send(zmq::buffer(str), more ? zmq::send_flags::sndmore : wait ? zmq::send_flags::none : zmq::send_flags::dontwait);
    // fmt::print("Sent message: {}\n", message.DebugString());
}

void recv_message(zmq::socket_t& socket, google::protobuf::Message &message, bool wait = true) {
    zmq::message_t result; // result{};
    socket.recv(result, wait ? zmq::recv_flags::none : zmq::recv_flags::dontwait);
    message.ParseFromArray(result.data(), (int)result.size());
    // fmt::print("Received message: {}\n", message.DebugString());
}

void recv_message_all(zmq::socket_t& socket, std::vector<zeromq_project::proto::Response>& responses, int expected)
{
    int i = 0;
    while (true) {
        zeromq_project::proto::Response response;
        recv_message(socket, response);
        responses.push_back(response);

        ++i;
        if(i >= expected)
        {
            int more = socket.get(zmq::sockopt::rcvmore);
            if (!more)
                break;
        }
    }
}

void message_to_json(const google::protobuf::Message &message, std::string &data) {
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = false;
    options.always_print_primitive_fields = true;
    options.preserve_proto_field_names = true;
    google::protobuf::util::MessageToJsonString(message, &data, options);
    // fmt::print("Message to json: {}\n", data);
}

void json_to_message(const std::string &data, google::protobuf::Message &message) {
    google::protobuf::util::JsonParseOptions options;
    google::protobuf::util::JsonStringToMessage(data, &message, options);
    // fmt::print("Json to message: {}\n", message.DebugString());
}

} // end namespace

#endif //ZEROMQ_PROJECT_UTILS_H
