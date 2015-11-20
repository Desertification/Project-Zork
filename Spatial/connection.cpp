//
// Created by thoma on 12/10/2015.
//

#include "connection.h"

Connection::Connection(Room* left,std::string left_description, std::string left_instruction,Room* right, std::string right_description, std::string right_instruction) {
    this->left = left; //one room
    this->right = right; // other room
    this->left_description = left_description;
    this->right_description = right_description;
    this->left_instruction = left_instruction;
    this->right_instruction = right_instruction;
}
std::string Connection::description(Room* from) {
    // return the description of the correct side of the connection
    if (from == left){
        return left_description;
    }else  if (from == right){
        return right_description;
    }
    return "";
}
std::string Connection::instruction(Room* from) {
    // return the instruction of the correct side of the connection
    if (from == left){
        return left_instruction;
    }else  if (from == right){
        return right_instruction;
    }
    return "";
}
Room* Connection::getOppositeRoom(Room* from){
    if (from == left){
        return right;
    }else if (from == right){
        return left;
    }
    return NULL;
}