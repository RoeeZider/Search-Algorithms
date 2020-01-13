cmake_minimum_required(VERSION 3.15)
project(advancedProg2)

set(CMAKE_CXX_STANDARD 14)

add_executable(advancedProg2 main.cpp ClientHandler.h Server.h CacheManager.h Solver.h MySerialServer.cpp MySerialServer.h MyTestClientHandler.cpp MyTestClientHandler.h FileCacheManager.cpp FileCacheManager.h stringReverser.cpp stringReverser.h State.h Searchable.h Searcher.h Searcher.cpp)