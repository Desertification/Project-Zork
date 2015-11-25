//
// Created by thoma on 25/11/2015.
//

#ifndef GAMETEST_INVENTORY_H
#define GAMETEST_INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory {
private:
    std::string name;
    std::vector<Item*> inventory;
    int weight;
public:
    Inventory(std::string);
    int getWeight();
    void removeItem(std::string);
    void removeItem(int);
    void addItem(Item*);
    Item* getItem(std::string);
    Item* getItem(int);
};


#endif //GAMETEST_INVENTORY_H
