#include <zmq.hpp>
#include "zhelpers.h"
#include <string>
#include <iostream>

// Adapted from zmqcpp/4.1.1@memsharded/stable test_package
int main() {
    //  Prepare our context and socket
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);

    std::cout << "Connecting to hello world server…" << std::endl;
    socket.connect("tcp://localhost:5555");

    //  Do 10 requests, waiting each time for a response
    for (int request_nbr = 0; request_nbr != 10; request_nbr++) {
        std::cout << "Sending Hello " << request_nbr << "…" << std::endl;
        s_send(socket, "Hello!!");

        //  Get the reply.
        auto s = s_recv(socket);
        std::cout << "Received " << s << " " << request_nbr << std::endl;
    }
    return 0;
}
