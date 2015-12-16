cmake_minimum_required(VERSION 3.3)
project(gametest)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(
        SOURCE_FILES main.cpp enities/entity.h enities/entity.cpp Spatial/room.cpp
        Spatial/room.h Spatial/connection.cpp Spatial/connection.h enities/Hero.cpp enities/Hero.h
        enities/Monster.cpp enities/Monster.h Command_parser/Game.cpp Command_parser/Game.h
        Command_parser/Command.cpp Command_parser/Command.h Command_parser/CommandParser.cpp
        Command_parser/CommandParser.h StartClass.cpp StartClass.h Inventory.cpp Inventory.h Items/Item.cpp Items/Item.h
        Items/TestItem.cpp Items/TestItem.h Lib.cpp Lib.h Items/SwingableItem.cpp Items/SwingableItem.h
        Items/Flashlight.cpp Items/Flashlight.h Items/Sword.cpp Items/Sword.h
        Items/ConsumableItem.cpp Items/ConsumableItem.h Items/HealthItem.cpp Items/HealthItem.h
        Items/Apple.cpp Items/Apple.h Items/BlackApple.cpp Items/BlackApple.h neopixel/I2cNeo.cpp neopixel/I2cNeo.h
        Map.cpp Map.h
        enities/monsters/Spider.cpp enities/monsters/Spider.h enities/monsters/Dracula.cpp enities/monsters/Dracula.h enities/monsters/Conquest.cpp enities/monsters/Conquest.h enities/monsters/Zombie.cpp enities/monsters/Zombie.h enities/monsters/AggressiveZombie.cpp enities/monsters/AggressiveZombie.h enities/monsters/Wendigo.cpp enities/monsters/Wendigo.h enities/monsters/War.cpp enities/monsters/War.h enities/monsters/Ortheos.cpp enities/monsters/Ortheos.h enities/monsters/Cyclops.cpp enities/monsters/Cyclops.h)
add_executable(gametest ${SOURCE_FILES})
target_link_libraries(gametest ${CURSES_LIBRARIES})