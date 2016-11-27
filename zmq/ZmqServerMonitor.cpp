#include "ZmqServerMonitor.h"
#include <chrono>

ZmqServerMonitor::ZmqServerMonitor(
        zmq::context_t &context,
        const ServerType serverType,
        const std::string &hostname,
        const uint16_t port,
        const std::string &parentEndpoint,
        const uint16_t maxTries,
        const std::chrono::milliseconds retryInterval)
    : context(context),
      serverType(serverType),
      hostname(hostname),
      port(port),
      parentEndpoint(parentEndpoint),
      maxTries(maxTries),
      tries(maxTries),
      retryInterval(retryInterval) {


}