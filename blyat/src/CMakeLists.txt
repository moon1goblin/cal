cmake_minimum_required(VERSION 3.25)

project(calendar)

# cpp standart
set (CMAKE_CXX_STANDARD 23)

# generate files for clangd lsp to work
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# compiler flags
string(APPEND CMAKE_CXX_FLAGS " -Wall")
string(APPEND CMAKE_CXX_FLAGS " -Wconversion")
string(APPEND CMAKE_CXX_FLAGS " -Wsign-conversion")
string(APPEND CMAKE_CXX_FLAGS " -Werror")

add_executable(run hellobitches.cpp)
