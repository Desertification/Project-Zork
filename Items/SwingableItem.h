//
// Created by thomas on 12/13/15.
//

#ifndef GAMETEST_SWINGABLEITEM_H
#define GAMETEST_SWINGABLEITEM_H


#include "Item.h"
class Entity;
class SwingableItem : public Item{
private:
protected:
    int damage = 0;
public:
    SwingableItem(std::string name,std::string description,int weight);
    void swing(Entity *user, Entity *monster);
};


#endif //GAMETEST_SWINGABLEITEM_H
