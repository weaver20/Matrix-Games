cmake_minimum_required(VERSION 3.16)
project(Ex3)

set(CMAKE_CXX_STANDARD 14)

include_directories(PartA)

add_executable(PartA
        PartA/Auxiliaries.cpp
        PartA/Auxiliaries.h
        PartA/IntMatrix.cpp
        PartA/IntMatrix.h
        PartA/test_partA.cpp)


add_executable(PartB
        PartB/Auxiliaries.cpp
        PartB/Auxiliaries.h
        PartB/Matrix.h
        PartB/partB_tester.cpp )

add_executable(PartC
        PartC/Soldier.cpp
        PartC/Medic.cpp
        PartC/Sniper.cpp
        PartC/Game.cpp
        PartC/Auxiliaries.cpp
        PartC/Character.cpp
        PartC/Exceptions.cpp
        PartC/partC_tester.cpp
        )
# Adds compile flags to compilation command of the target hello.
# first arg: name of the target
# second arg: PRIVATE (can also be PUBLIC or INTERFACE)
# rest of args: flags to add to the command
#target_compile_options(PartA -Wall -Werror -pedantic-errors -DNDEBUG)