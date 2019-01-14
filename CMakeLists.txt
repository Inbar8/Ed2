cmake_minimum_required(VERSION 3.13)
project(Ed2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

add_executable(Ed2 main.cpp Server.h MySerialServer.h
        Solver.h MyParallelServer.h
        CacheManager.h
        FileCacheManager.h  MyClientHandler.h ClientHandler.h
        Searchable.h Searcher.h BestFirstSearch.h
        BFS.cpp BFS.h DFS.cpp DFS.h MatrixMaze.h
        MySerialServer.cpp Socket.h Socket.cpp MyException.h StreamInput.h
        StreamOutput.h ProtocolMatrix.h Protocol.h ProtocolTrace.h checkcheck.h)