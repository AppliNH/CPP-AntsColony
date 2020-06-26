cmake_minimum_required(VERSION 3.13.4)
set(PROJECT_NAME CPP_AntsColony)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")
set(CMAKE_CXX_STANDARD 17)


set(SFML_DIR "lib/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS audio graphics window system)


include_directories(lib)
add_executable(${PROJECT_NAME} main.cpp lib/ants/living_ant/LivingAnt.cpp lib/ants/living_ant/LivingAnt.h lib/ants/ant/Ant.cpp lib/ants/ant/Ant.h  lib/food/Food.cpp lib/food/Food.h lib/ants/ant_egg/AntEgg.cpp lib/ants/ant_egg/AntEgg.h lib/ants/ant_warrior/AntWarrior.cpp lib/ants/ant_warrior/AntWarrior.h lib/ants/ant_young_queen/AntYoungQueen.cpp lib/ants/ant_young_queen/AntYoungQueen.h lib/ant_hill/AntHill.cpp lib/ant_hill/AntHill.h lib/environment/Environment.cpp lib/environment/Environment.h lib/pheromone/Pheromone.cpp lib/pheromone/Pheromone.h lib/obstacle/Obstacle.cpp lib/obstacle/Obstacle.h lib/ants/ant_worker/AntWorker.cpp lib/ants/ant_worker/AntWorker.h lib/ants/ant_queen/AntQueen.cpp lib/ants/ant_queen/AntQueen.h lib/square_box/SquareBox.cpp lib/square_box/SquareBox.h lib/game/Game.cpp lib/game/Game.h)
if (SFML_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-system sfml-window)
endif ()


