cmake_minimum_required(VERSION 3.25)

project(calendar)

# cpp standart
set(CMAKE_CXX_STANDARD 23)

# generate files for clangd lsp to work
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# compiler flags
string(APPEND CMAKE_CXX_FLAGS " -Wall")
# string(APPEND CMAKE_CXX_FLAGS " -Wconversion")
# string(APPEND CMAKE_CXX_FLAGS " -Wsign-conversion")
string(APPEND CMAKE_CXX_FLAGS " -Werror")

add_executable(run src/hi.cpp)

#-------------------------------------------------------
# load environment variables from .env file

file(STRINGS ${CMAKE_HOME_DIRECTORY}/.env ENV_FILE)
foreach(VAR ${ENV_FILE})
    string(REGEX MATCH "^[^=]*" KEY ${VAR})
    string(REGEX REPLACE "^[^=]*=" "" VALUE ${VAR})
    set(ENV{${KEY}} ${VALUE})
	# define preprocessor macros for them
	target_compile_definitions(run PRIVATE ${KEY}=${VALUE})
	# message(STATUS $ENV{${KEY}})
endforeach()

#
# target_compile_definitions(run PRIVATE MY_MACRO=$ENV{MYSQL_USER})

#-------------------------------------------------------

# mysql-connector library

# костыль для меня потому что я не хочу ебаться с этим дальше ~moon1goblin
set(mysql-concpp_DIR "/opt/homebrew/Cellar/mysql-connector-c++/9.3.0/")
# set(mysql-concpp_DIR "/home/linuxbrew/.linuxbrew/Cellar/mysql-connector-c++/9.3.0/")

find_package(mysql-concpp REQUIRED)

target_link_libraries(run 
	mysql::concpp
)
