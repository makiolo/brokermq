cmake_minimum_required(VERSION 3.27)
project(zeromq_project)

find_package(ZeroMQ CONFIG REQUIRED)
find_package(cppzmq CONFIG REQUIRED)
find_package(czmq CONFIG REQUIRED)
find_package(Protobuf CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(fmt CONFIG REQUIRED)
find_library(nghttp2_LIBRARY NAMES nghttp2 REQUIRED)
find_library(nghttp2_asio_LIBRARY NAMES nghttp2_asio REQUIRED)
find_path(AZMQ_INCLUDE_DIRS "azmq/actor.hpp")

set(CMAKE_CXX_STANDARD 20)

set(COMMON_INCLUDES
        ${Protobuf_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/generated
)

protobuf_generate_cpp(
        GEN_SRC
        GEN_H
        ${CMAKE_CURRENT_SOURCE_DIR}/event.proto)

protobuf_generate_python(
        PROTO_PY
        ${CMAKE_CURRENT_SOURCE_DIR}/event.proto)

add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/generated/event.cpp POST_BUILD
        MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/event.proto
        DEPENDS ${GEN_SRC}
        COMMAND ${CMAKE_COMMAND} -E copy ${GEN_SRC} ${CMAKE_CURRENT_SOURCE_DIR}/generated/event.cpp
)
add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/generated/event.pb.h POST_BUILD
        MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/event.proto
        DEPENDS ${GEN_H}
        COMMAND ${CMAKE_COMMAND} -E copy ${GEN_H} ${CMAKE_CURRENT_SOURCE_DIR}/generated/event.pb.h
)
add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/generated/event.py POST_BUILD
        MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/event.proto
        DEPENDS ${PROTO_PY}
        COMMAND ${CMAKE_COMMAND} -E copy ${PROTO_PY} ${CMAKE_CURRENT_SOURCE_DIR}/generated/event.py
)

set(PROTOCOL_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/event.pb.h
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/event.py
)


add_compile_definitions(DEBUG=1)


add_executable(client)
target_sources(client PRIVATE client.cpp ${PROTOCOL_FILES})
target_include_directories(client PRIVATE ${COMMON_INCLUDES})
target_include_directories(client PRIVATE ${AZMQ_INCLUDE_DIRS})
target_link_libraries(client PRIVATE fmt::fmt-header-only)
target_link_libraries(client PRIVATE libzmq libzmq-static)
target_link_libraries(client PRIVATE cppzmq cppzmq-static)
target_link_libraries(client PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)


add_executable(worker_rpc)
target_sources(worker_rpc PRIVATE worker_rpc.cpp ${PROTOCOL_FILES})
target_include_directories(worker_rpc PRIVATE ${COMMON_INCLUDES})
target_link_libraries(worker_rpc PRIVATE fmt::fmt-header-only)
target_link_libraries(worker_rpc PRIVATE libzmq libzmq-static)
target_link_libraries(worker_rpc PRIVATE cppzmq cppzmq-static)
target_link_libraries(worker_rpc PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)


add_executable(broker_rpc)
target_sources(broker_rpc PRIVATE broker_rpc.cpp ${PROTOCOL_FILES})
target_include_directories(broker_rpc PRIVATE ${COMMON_INCLUDES})
target_link_libraries(broker_rpc PRIVATE fmt::fmt-header-only)
target_link_libraries(broker_rpc PRIVATE libzmq libzmq-static)
target_link_libraries(broker_rpc PRIVATE cppzmq cppzmq-static)
target_link_libraries(broker_rpc PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)



add_executable(broker_balancer)
target_sources(broker_balancer PRIVATE broker_balancer.cpp ${PROTOCOL_FILES})
target_include_directories(broker_balancer PRIVATE ${COMMON_INCLUDES})
target_link_libraries(broker_balancer PRIVATE fmt::fmt-header-only)
target_link_libraries(broker_balancer PRIVATE libzmq libzmq-static)
target_link_libraries(broker_balancer PRIVATE cppzmq cppzmq-static)
target_link_libraries(broker_balancer PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)


add_executable(worker_balancer)
target_sources(worker_balancer PRIVATE worker_balancer.cpp ${PROTOCOL_FILES})
target_include_directories(worker_balancer PRIVATE ${COMMON_INCLUDES})
target_link_libraries(worker_balancer PRIVATE fmt::fmt-header-only)
target_link_libraries(worker_balancer PRIVATE libzmq libzmq-static)
target_link_libraries(worker_balancer PRIVATE cppzmq cppzmq-static)
target_link_libraries(worker_balancer PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)


add_executable(endpoint)
target_sources(endpoint PRIVATE endpoint.cpp ${PROTOCOL_FILES})
target_include_directories(endpoint PRIVATE ${COMMON_INCLUDES})
target_include_directories(endpoint PRIVATE ${BOOST_LIBRARY_INCLUDES})
target_link_libraries(endpoint PRIVATE fmt::fmt-header-only)
target_link_libraries(endpoint PRIVATE libzmq libzmq-static)
target_link_libraries(endpoint PRIVATE cppzmq cppzmq-static)
target_link_libraries(endpoint PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
target_link_libraries(endpoint PRIVATE ${nghttp2_asio_LIBRARY})
target_link_libraries(endpoint PRIVATE ${nghttp2_LIBRARY})
target_link_libraries(endpoint PRIVATE Boost::boost Boost::system)
target_link_libraries(endpoint PRIVATE OpenSSL::SSL OpenSSL::Crypto)


add_executable(publisher)
target_sources(publisher PRIVATE publisher.cpp ${PROTOCOL_FILES})
target_include_directories(publisher PRIVATE ${COMMON_INCLUDES})
target_link_libraries(publisher PRIVATE fmt::fmt-header-only)
target_link_libraries(publisher PRIVATE libzmq libzmq-static)
target_link_libraries(publisher PRIVATE cppzmq cppzmq-static)
target_link_libraries(publisher PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
target_link_libraries(publisher PRIVATE czmq czmq-static)


add_executable(subscriber)
target_sources(subscriber PRIVATE subscriber.cpp ${PROTOCOL_FILES})
target_include_directories(subscriber PRIVATE ${COMMON_INCLUDES})
target_link_libraries(subscriber PRIVATE fmt::fmt-header-only)
target_link_libraries(subscriber PRIVATE libzmq libzmq-static)
target_link_libraries(subscriber PRIVATE cppzmq cppzmq-static)
target_link_libraries(subscriber PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
target_link_libraries(subscriber PRIVATE czmq czmq-static)


add_executable(broker_pubsub)
target_sources(broker_pubsub PRIVATE broker_pubsub.cpp ${PROTOCOL_FILES})
target_include_directories(broker_pubsub PRIVATE ${COMMON_INCLUDES})
target_link_libraries(broker_pubsub PRIVATE fmt::fmt-header-only)
target_link_libraries(broker_pubsub PRIVATE libzmq libzmq-static)
target_link_libraries(broker_pubsub PRIVATE cppzmq cppzmq-static)
target_link_libraries(broker_pubsub PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
target_link_libraries(broker_pubsub PRIVATE czmq czmq-static)


# broker-pipeline
# ventilator -> worker -> sink

# Ver ZeroMQ asincrono: https://composed.blog/jsonrpc/zeromq-async

