#pragma once

#include "zmq.hpp"
#include "ConnectionInfo.h"

class ZmqFailoverMonitor {
public:
    ZmqFailoverMonitor(
        zmq::context_t &context,
        const ConnectionInfo &primary,
        const ConnectionInfo &backup);

private:
    zmq::context_t &context;
    const ConnectionInfo &primary;
    const ConnectionInfo &backup;
};
