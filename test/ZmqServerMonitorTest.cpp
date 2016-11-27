#include "catch.hpp"
#include "../zmq/ZmqServerMonitor.h"

TEST_CASE("Connect", "[ZMQ][ZmqServerMonitor][Connect]") {
    zmq::context_t context;
    zmq::socket_t server(context, ZMQ_ROUTER);
    server.bind("tcp://localhost:5050");
    zmq::socket_t parent(context, ZMQ_REP);
    const std::string ParentEndpoint{"inproc://test.alertee"};
    parent.bind(ParentEndpoint.c_str());

    ZmqServerMonitor serverMonitor(context, ServerType::Primary, "localhost", 5050,
                                   ParentEndpoint, 0, std::chrono::seconds(2));


}