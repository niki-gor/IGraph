cmake_minimum_required(VERSION 3.24)
project(IGraph)

set(CMAKE_CXX_STANDARD 23)

add_executable(IGraph ListGraph.cpp ListGraph.hpp MatrixGraph.cpp MatrixGraph.hpp SetGraph.cpp SetGraph.hpp ArcGraph.cpp ArcGraph.hpp main.cpp)
