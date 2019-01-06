cmake_minimum_required(VERSION 3.13)
project(Ed2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ed2 main.cpp ClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h MyTestHandler.cpp MyTestHandler.h)