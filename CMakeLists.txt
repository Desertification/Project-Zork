cmake_minimum_required(VERSION 3.3)
project(gametest)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(
        SOURCE_FILES main.cpp Living_Things/entity.h Living_Things/entity.cpp Spatial/room.cpp
        Spatial/room.h Spatial/connection.cpp Spatial/connection.h Living_Things/Hero.cpp Living_Things/Hero.h
        Living_Things/Monster.cpp Living_Things/Monster.h Command_parser/Game.cpp Command_parser/Game.h
        Command_parser/Command.cpp Command_parser/Command.h Command_parser/CommandParser.cpp
        Command_parser/CommandParser.h StartClass.cpp StartClass.h Inventory.cpp Inventory.h Items/Item.cpp Items/Item.h
        Items/TestItem.cpp Items/TestItem.h Lib.cpp Lib.h)
add_executable(gametest ${SOURCE_FILES})
target_link_libraries(gametest ${CURSES_LIBRARIES})