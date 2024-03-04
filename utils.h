//
// Created by ricardo on 3/4/24.
//

#ifndef ZEROMQ_PROJECT_UTILS_H
#define ZEROMQ_PROJECT_UTILS_H

#include <google/protobuf/util/json_util.h>

namespace protomq {

void send_message(zmq::socket_t *socket, const google::protobuf::Message &message) {
    std::string str;
    message.SerializeToString(&str);
    socket->send(zmq::buffer(str), zmq::send_flags::none);
}

void recv_message(zmq::socket_t *socket, google::protobuf::Message &message) {
    zmq::message_t resultset{};
    socket->recv(resultset, zmq::recv_flags::none);
    message.ParseFromArray(resultset.data(), resultset.size());
}

void message_to_json(const google::protobuf::Message &mutation, std::string& data) {
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = false;
    options.always_print_primitive_fields = true;
    options.preserve_proto_field_names = true;
    google::protobuf::util::MessageToJsonString(mutation, &data, options);
}

}

#endif //ZEROMQ_PROJECT_UTILS_H
