//
// Created by thomas on 12/13/15.
//

#ifndef GAMETEST_CONSUMABLEITEM_H
#define GAMETEST_CONSUMABLEITEM_H


#include "Item.h"

class ConsumableItem : public Item {
private:
public:
    ConsumableItem(std::string name, std::string description, int weight);
};


#endif //GAMETEST_CONSUMABLEITEM_H
