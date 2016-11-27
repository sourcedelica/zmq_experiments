#include <zmq.hpp>
#include "zhelpers.h"
#include <string>
#include <iostream>

// Adapted from zmqcpp/4.1.1@memsharded/stable test_package
int main() {
    //  Prepare our context and socket
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    socket.bind("tcp://*:5555");

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        //  Wait for next request from client
        auto s = s_recv(socket);
        std::cout << "Received " << s << std::endl;

        //  Send reply back to client
        s_send(socket, "World!");
    }
#pragma clang diagnostic pop
    return 0;
}