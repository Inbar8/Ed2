cmake_minimum_required(VERSION 3.13)
project(Ed2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ed2 main.cpp Server.h MySerialServer.cpp MySerialServer.h Solver.cpp Solver.h MyParallelServer.cpp MyParallelServer.h)