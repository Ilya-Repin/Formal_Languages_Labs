cmake_minimum_required(VERSION 3.29)
project(FormalLanguagesLabs)

set(CMAKE_CXX_STANDARD 20)

add_executable(FormalLanguagesLabs lab_1/lab_1.cpp
        lab_1/src/Language.cpp
        lab_1/src/Language.h
        lab_1/src/Grammar.cpp
        lab_1/src/Grammar.h)
