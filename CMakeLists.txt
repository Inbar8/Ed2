cmake_minimum_required(VERSION 3.13)
project(Ed2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

add_executable(Ed2 main.cpp server_utility/Server.h server_utility/MySerialServer.h
        Solver.h server_utility/MyParallelServer.h
        CacheManager.h
        FileCacheManager.h  MyClientHandler.h ClientHandler.h
        Searchable.h Searcher.h BestFirstSearch.h
        BFS.h DFS.h MatrixMaze.h
        server_utility/MySerialServer.cpp server_utility/Socket.h server_utility/Socket.cpp MyException.h server_utility/StreamInput.h
        server_utility/StreamOutput.h protocols/ProtocolMatrix.h protocols/Protocol.h protocols/ProtocolTrace.h checkcheck.h SolverAlgorithms.h)
