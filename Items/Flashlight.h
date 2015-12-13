//
// Created by thomas on 12/13/15.
//

#ifndef GAMETEST_FLASHLIGHT_H
#define GAMETEST_FLASHLIGHT_H


#include "SwingableItem.h"

class Flashlight : public SwingableItem{
private:
protected:
public:
    Flashlight();
    void swing(Entity*user,Entity*monster);
};


#endif //GAMETEST_FLASHLIGHT_H
