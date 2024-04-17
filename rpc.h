//
// Created by ricardo on 3/9/24.
//

#ifndef ZEROMQ_PROJECT_RPC_H
#define ZEROMQ_PROJECT_RPC_H

#include "generated/event.pb.h"

namespace protomq {

// method is calculation formula
// request is product_type
// response is calculation returned

zeromq_project::proto::Response calculate1(const zeromq_project::proto::Mutation &command)
{
    zeromq_project::proto::Response response;
    response.set_code(201);
    response.set_age( 9999 );
    response.set_ticket_id(command.ticket_id());
    return response;
}

zeromq_project::proto::Response calculate2(const zeromq_project::proto::Mutation &command)
{
    zeromq_project::proto::Response response;
    response.set_code(202);
    response.set_age( command.age() );
    response.set_ticket_id(command.ticket_id());
    return response;
}

}

#endif //ZEROMQ_PROJECT_RPC_H
