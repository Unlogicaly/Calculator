cmake_minimum_required(VERSION 3.13)
project(Calculator_debug)

set(CMAKE_CXX_STANDARD 14)

add_executable(Calculator_debug main.cpp std_lib_facilities.h token.cpp token.h variable.cpp variable.h states_generation.cpp states_generation.h words_treatment.cpp words_treatment.h constants.h define_token.cpp define_token.h get_token.cpp get_token.h containers.cpp containers.h grammar.cpp grammar.h)