#pragma once

#include <chrono>
#include "zmq.hpp"

enum class ServerType { Primary, Backup };
constexpr const char *ServerTypeName(ServerType serverType) {
    return serverType == ServerType::Primary ? "primary" : "backup";
}

enum class ServerStatus { Up, Down, Failed, Stopped };

class ZmqServerMonitor {
public:
    ZmqServerMonitor(
        zmq::context_t &context,
        const ServerType serverType,
        const std::string &hostname,
        const uint16_t port,
        const std::string &parentEndpoint,
        const uint16_t maxTries,
        const std::chrono::milliseconds retryInterval);

    struct StatusMessage {
        ServerStatus status;
        ServerType type;
    };

private:
    zmq::context_t &context;
    const ServerType serverType;
    const std::string hostname;
    const uint16_t port;
    const std::string parentEndpoint;
    const uint16_t maxTries;
    const std::chrono::milliseconds retryInterval;

    int tries;
};
