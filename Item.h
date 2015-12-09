//
// Created by thoma on 25/11/2015.
//

#ifndef GAMETEST_ITEM_H
#define GAMETEST_ITEM_H

#include <string>
#include "Living_Things/Hero.h"

class Item {
private:
    std::string name;
    std::string description;
    int weight;
public:
    Item(std::string, std::string, int);
    std::string getName();
    std::string getDescription();
    int getWeight();
    virtual void use() = 0;
};


#endif //GAMETEST_ITEM_H
