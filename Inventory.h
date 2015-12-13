//
// Created by thoma on 25/11/2015.
//

#ifndef GAMETEST_INVENTORY_H
#define GAMETEST_INVENTORY_H

#include <vector>
#include "Item.h"
class Item;
class Inventory {
private:
    std::string name;
    std::vector<Item*> itemlist;
    int weight;
public:
    Inventory(std::string name);
    int getWeight();
    std::string getName();
    void setName(std::string name);
    void removeItem(std::string item_name);
    void addItem(Item* Item_pointer);
    Item* getItem(std::string item_name);
    std::vector<Item*>* getItems();
};


#endif //GAMETEST_INVENTORY_H
