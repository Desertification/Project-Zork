//
// Created by thomas on 12/2/15.
//

#ifndef GAMETEST_TESTITEM_H
#define GAMETEST_TESTITEM_H

#include "Item.h"

class TestItem : public Item{
private:
public:
    TestItem(std::string name,std::string description,int weight);

    void use();
};


#endif //GAMETEST_TESTITEM_H
