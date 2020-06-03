cmake_minimum_required(VERSION 3.10.2)
project (Ex3)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(PartA
        PartA/Auxiliaries.cpp
        PartA/Auxiliaries.h
        PartA/test_partA.cpp)

# Adds compile flags to compilation command of the target hello.
# first arg: name of the target
# second arg: PRIVATE (can also be PUBLIC or INTERFACE)
# rest of args: flags to add to the command
#target_compile_options(PartA -Wall -Werror -pedantic-errors -DNDEBUG)