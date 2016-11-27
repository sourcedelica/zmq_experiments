#include "catch.hpp"
#include "../zmq/ZmqServerMonitor.h"

TEST_CASE("Connect", "[ZMQ][ZmqServerMonitor][Connect]") {
    zmq::context_t context;
    zmq::socket_t server(context, ZMQ_ROUTER);
    server.bind("tcp://localhost:5050");
    zmq::socket_t alertee(context, ZMQ_REP);
    const std::string AlerteeEndpoint{"inproc://test.alertee"};
    alertee.bind(AlerteeEndpoint.c_str());

    ZmqServerMonitor serverMonitor(context, ServerType::Primary, "localhost", 5050,
                                   AlerteeEndpoint, 0, std::chrono::seconds(2));
    zmq::pollitem_t items[] = {
            {server, 0, ZMQ_POLLIN, 0},
            {alertee, 0, ZMQ_POLLIN, 0}
    };

    zmq::poll(items, 2, -1);
}