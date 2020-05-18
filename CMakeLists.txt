cmake_minimum_required(VERSION 3.16)
project(CPP_AntsColony)

set(CMAKE_CXX_STANDARD 17)
include_directories(lib)
add_executable(CPP-AntsColony lib/ant/Ant.cpp lib/food/Food.cpp main.cpp)