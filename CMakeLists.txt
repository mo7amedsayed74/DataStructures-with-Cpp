cmake_minimum_required(VERSION 3.23)
project(dataStract)

set(CMAKE_CXX_STANDARD 14)

add_executable(dataStract main.cpp stack.h InfixToPostfix.h PostfixEvaluation.h)
