cmake_minimum_required(VERSION 3.15)
project(mile_stone2)

SET(CMAKE_CXX_FLAGS -pthread)

add_executable(mile_stone2 main.cpp ClientHandler.h Solver.h Server.h
        CacheManager.h FileCacheManager.cpp MySerialServer.cpp
        Solver.h StringReverser.cpp Searcher.h ISearchable.h ISearcher.h
        BestFirstSearch.h State.h Searchable.h CompareTrail.h MyClientHandler.cpp SolverSearch.cpp
        Point.cpp Matrix.h MyTestClientHandler.cpp BFS.h DFS.h AStar.h
        MyParallelServer.h CompareFScore.h MyParallelServer.cpp RunMatrix.cpp Boot.h)