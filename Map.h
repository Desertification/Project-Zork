//
// Created by alex on 12/16/15.
//

#ifndef GAMETEST_MAP_H
#define GAMETEST_MAP_H


#include "Spatial/room.h"

std::vector<Room *> getRooms();
std::vector<Connection *> getConnections(std::vector<Room *> rooms);
void addConnectionsToRooms(std::vector<Room *> rooms, std::vector<Connection *> connections);

#endif //GAMETEST_MAP_H
