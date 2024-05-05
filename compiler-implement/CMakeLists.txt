cmake_minimum_required(VERSION 3.25)
project()

set(CMAKE_CXX_STANDARD 17)
add_executable(main.cpp runRE/NFA2DFA.cpp test/1.c test/template.cpp runGrammar/test.cpp runGrammar/test.cpp)
