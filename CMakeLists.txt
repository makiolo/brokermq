cmake_minimum_required(VERSION 3.27)
project(zeromq_project LANGUAGES CXX)

find_package(ZeroMQ CONFIG REQUIRED)
find_package(cppzmq CONFIG REQUIRED)
find_package(Protobuf CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 20)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/generated)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS event.proto)
file(COPY ${PROTO_SRCS} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/generated)
file(COPY ${PROTO_HDRS} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/generated)

# el número de clientes es incontrolable, pero debemos medirlo y poner un número de servers proporcional
add_executable(client client.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(client PRIVATE libzmq libzmq-static)
target_link_libraries(client PRIVATE cppzmq cppzmq-static)
target_link_libraries(client PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)

# tantos servers como cores
add_executable(server server.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(server PRIVATE libzmq libzmq-static)
target_link_libraries(server PRIVATE cppzmq cppzmq-static)
target_link_libraries(server PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)

# tantos brokers como maquinas
add_executable(broker_rpc broker_rpc.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(broker_rpc PRIVATE libzmq libzmq-static)
target_link_libraries(broker_rpc PRIVATE cppzmq cppzmq-static)
target_link_libraries(broker_rpc PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)

# tantos balancers como paises o edificios
add_executable(broker_balancer broker_balancer.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(broker_balancer PRIVATE libzmq libzmq-static)
target_link_libraries(broker_balancer PRIVATE cppzmq cppzmq-static)
target_link_libraries(broker_balancer PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)

# broker-rpc
# proxy req->router->dealer->rep para crear un broker RPC

# Los brokers tiene state: cuantos workers tienen.
# usan pub-sub para propagar su state con otros brokers
# un mensaje puede ser rechazado si:
# - no hay workers disponibles
# - hay otro broker a quien pedir ayuda.
# Todo worker puede hacer cualquier tarea. Aunque es posible que un worker se especialice ?

# broker-loadbalancer
# router-router para crear un broker

# broker-pubsub
# publisher eventos
# router xpub/xsub para crear un broker
# subscriber eventos

# broker-pipeline
# ventilator -> worker -> sink

