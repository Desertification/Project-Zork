//
// Created by thoma on 25/11/2015.
//

#ifndef GAMETEST_ITEM_H
#define GAMETEST_ITEM_H

#include <string>
//#include "Living_Things/entity.h"
//#include "Spatial/room.h"
class Entity;
class Room;
class Item {
private:
    std::string name;
    std::string description;
    int weight;
protected:
    bool swingable = false;
    bool usable = false;
    bool equipable = false;
    bool consumable = false;
public:
    Item(std::string name, std::string description, int weight);
    std::string getName();
    std::string getDescription();
    int getWeight();
    bool isSwingable();
    bool isUsable();
    bool isEquipable();
    bool isConsumable();
    virtual void swing(Entity* user,Entity* monster);
    virtual void use(Entity* user, Room* room);
    virtual void equip(Entity* user);
    virtual void consume(Entity* user);
};


#endif //GAMETEST_ITEM_H
