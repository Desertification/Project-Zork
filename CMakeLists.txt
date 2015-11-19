cmake_minimum_required(VERSION 3.3)
project(gametest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp entity.h entity.cpp room.cpp room.h connection.cpp connection.h CommandInterpreter.cpp CommandInterpreter.h Hero.cpp Hero.h Monster.cpp Monster.h CommandParser.cpp CommandParser.h Command.cpp Command.h)
add_executable(gametest ${SOURCE_FILES})