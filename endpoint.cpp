#include <iostream>
#include <nghttp2/asio_http2_server.h>
#include <fmt/core.h>

using namespace nghttp2::asio_http2;
using namespace nghttp2::asio_http2::server;

int main(int argc, char *argv[]) {
    boost::system::error_code ec;
    http2 server;

    fmt::print("Server started in 3000.\n");

    server.handle("/", [](const request &req, const response &res) {
        fmt::print("Request received\n");
        res.write_head(200);
        res.end("hello, world\n");
    });

    if (server.listen_and_serve(ec, "localhost", "3000")) {
        std::cerr << "error: " << ec.message() << std::endl;
    }
}

