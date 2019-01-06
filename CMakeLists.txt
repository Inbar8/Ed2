cmake_minimum_required(VERSION 3.13)
project(Ed2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ed2 main.cpp Server.h MySerialServer.cpp MySerialServer.h Solver.h MyParallelServer.cpp MyParallelServer.h ClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h MyTestHandler.cpp MyTestHandler.h)