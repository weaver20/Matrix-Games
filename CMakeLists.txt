cmake_minimum_required(VERSION 3.16)
project(Ex3)

set(CMAKE_CXX_STANDARD 14)

include_directories(PartA)

add_executable(PartA
        PartA/Auxiliaries.cpp
        PartA/Auxiliaries.h
        PartA/IntMatrix.cpp
        PartA/IntMatrix.h
        PartA/partA_tests.cpp)


add_executable(PartB
        PartB/Auxiliaries.cpp
        PartB/Auxiliaries.h
        PartB/Matrix.h
        PartB/test_partB.cpp )

add_executable(PartC
        PartC/Soldier.cpp
        PartC/Medic.cpp
        PartC/Sniper.cpp
        PartC/Game.cpp
        PartC/Auxiliaries.cpp
        partC/test_partC.cpp)
# Adds compile flags to compilation command of the target hello.
# first arg: name of the target
# second arg: PRIVATE (can also be PUBLIC or INTERFACE)
# rest of args: flags to add to the command
#target_compile_options(PartA -Wall -Werror -pedantic-errors -DNDEBUG)