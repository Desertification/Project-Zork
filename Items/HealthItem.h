//
// Created by thomas on 12/13/15.
//

#ifndef GAMETEST_HEALINGITEM_H
#define GAMETEST_HEALINGITEM_H


#include "ConsumableItem.h"

class HealthItem : public ConsumableItem {
private:
    int health_modifier;
public:
    HealthItem(std::string name,std::string description,int weight, int health_modifier);
    virtual void consume(Entity*user);
};


#endif //GAMETEST_HEALINGITEM_H
