cmake_minimum_required(VERSION 3.3)
project(gametest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Living_Things/entity.h Living_Things/entity.cpp room.cpp room.h connection.cpp connection.h Living_Things/Hero.cpp Living_Things/Hero.h Living_Things/Monster.cpp Living_Things/Monster.h Command_parser/Game.cpp Command_parser/Game.h Command_parser/Command.cpp Command_parser/Command.h Command_parser/CommandParser.cpp Command_parser/CommandParser.h)
add_executable(gametest ${SOURCE_FILES})