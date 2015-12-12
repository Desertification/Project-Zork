//
// Created by thoma on 25/11/2015.
//

#ifndef GAMETEST_ITEM_H
#define GAMETEST_ITEM_H

#include <string>

class Item {
private:
    std::string name;
    std::string description;
    int weight;
public:
    Item(std::string name, std::string description, int weight);
    std::string getName();
    std::string getDescription();
    int getWeight();
    virtual void use() = 0;
};


#endif //GAMETEST_ITEM_H
