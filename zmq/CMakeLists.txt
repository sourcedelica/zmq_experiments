set(HELLO_SERVER_SOURCES hello_server.cpp)
set(HELLO_CLIENT_SOURCES hello_client.cpp)
set(RECONNECT_CLIENT_SOURCES
        ConnectionInfo.h ZmqServerMonitor.cpp ZmqFailoverMonitor.cpp reconnect_client.cpp)

add_executable(hello-server ${HELLO_SERVER_SOURCES})
add_executable(hello-client ${HELLO_CLIENT_SOURCES})
add_executable(reconnect-client ${RECONNECT_CLIENT_SOURCES})

