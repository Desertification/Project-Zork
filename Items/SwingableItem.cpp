//
// Created by thomas on 12/13/15.
//

#include "SwingableItem.h"

SwingableItem::SwingableItem(std::string name, std::string description, int weight) : Item(name,description,weight) {
    swingable = true;
}
void SwingableItem::swing(Entity *user, Entity *monster) {
    monster->takeDamage(user->getDamage() + damage,user->getQuickness());
}