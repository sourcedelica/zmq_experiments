#pragma once

#include <string>
#include <sstream>

struct ConnectionInfo {
    std::string host;
    uint16_t port;
    uint16_t groupsPort;

    std::string toString() const {
        std::stringstream ss;
        ss << host << ":" << port;
        return ss.str();
    }
};