//
// Created by thomas on 12/13/15.
//

#include "Flashlight.h"

Flashlight::Flashlight() : SwingableItem("flashlight","Just an ordinary flashlight with unlimited battery power", 1, 0) {

}

void Flashlight::swing(Entity *user, Entity *monster) {
    if (monster->getName() == "dracula") {
        monster->takeDamage(999,user->getQuickness());
    }
    else {
        Item::swing(user, monster); // prints line that it's no use
    }
}
