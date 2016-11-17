cmake_minimum_required(VERSION 3.5)
project(experiments)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Run "conan install .." in the "build" directory to create this file
include(conanbuildinfo.cmake)
conan_basic_setup()

# Automatically add CAF libs to all executables
macro (add_executable _name)
    _add_executable(${ARGV})
    if (TARGET ${_name})
        target_link_libraries(${_name} ${CONAN_LIBS_ZMQ})
    endif()
endmacro()

# CAF
include_directories(${CONAN_INCLUDE_DIRS_ZMQ})

# Boost
find_package(Boost COMPONENTS REQUIRED chrono filesystem thread)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif ()

# Protobuf
find_package(Protobuf)

add_subdirectory(zmq)
add_subdirectory(test)
