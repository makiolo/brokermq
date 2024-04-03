//
// Created by ricardo on 3/9/24.
//

#ifndef ZEROMQ_PROJECT_RPC_H
#define ZEROMQ_PROJECT_RPC_H

#include "generated/event.pb.h"

namespace protomq {

zeromq_project::proto::Response calculate1(const zeromq_project::proto::Mutation &command)
{
    zeromq_project::proto::Response response;
    response.set_code(201);
    return response;
}

zeromq_project::proto::Response calculate2(const zeromq_project::proto::Mutation &command)
{
    zeromq_project::proto::Response response;
    response.set_code(202);
    response.set_age( command.age() );
    return response;
}

}

#endif //ZEROMQ_PROJECT_RPC_H
