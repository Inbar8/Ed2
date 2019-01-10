cmake_minimum_required(VERSION 3.13)
project(Ed2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ed2 main.cpp Server.h MySerialServer.h
        Solver.h MyParallelServer.h
        CacheManager.h FileCacheManager.cpp
        FileCacheManager.h  MyClientHandler.h ClientHandler.h StringReverser.h
        StringReverser.cpp Searchable.h Searcher.h BestFirstSearch.h
        BFS.cpp BFS.h DFS.cpp DFS.h MatrixMaze.cpp MatrixMaze.h
        )