//
// Created by thomas on 12/13/15.
//

#include "ConsumableItem.h"

ConsumableItem::ConsumableItem(std::string name, std::string description, int weight) : Item(name,description,weight){
    this->consumable = true;
}
