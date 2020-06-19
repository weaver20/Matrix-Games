cmake_minimum_required(VERSION 3.16)
project(Ex3)

set(CMAKE_CXX_STANDARD 14)

include_directories(PartA)

add_executable(PartA
        PartA/Auxiliaries.cpp
        PartA/Auxiliaries.h
        PartA/IntMatrix.cpp
        PartA/IntMatrix.h
<<<<<<< HEAD
        PartA/partA_tests.cpp)
=======
        PartA/test_partA.cpp )

add_executable(PartB
        PartA/Auxiliaries.cpp
        PartA/Auxiliaries.h
        PartB/Matrix.cpp
        PartB/Matrix.h
        PartB/test_partB.cpp )
>>>>>>> 5dd51a5138e3ff361eeaec2bc63973307d8aa586

# Adds compile flags to compilation command of the target hello.
# first arg: name of the target
# second arg: PRIVATE (can also be PUBLIC or INTERFACE)
# rest of args: flags to add to the command
#target_compile_options(PartA -Wall -Werror -pedantic-errors -DNDEBUG)