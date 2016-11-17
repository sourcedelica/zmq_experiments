set(HELLO_SERVER_SOURCES hello_server.cpp)
set(HELLO_CLIENT_SOURCES hello_client.cpp)

add_executable(hello-server ${HELLO_SERVER_SOURCES})
add_executable(hello-client ${HELLO_CLIENT_SOURCES})
