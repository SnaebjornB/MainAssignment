#include "sides.h"

Sides::Sides(string name, int price, char size){
    this->name = name;
    this->price = price;
    this->size = size;
}

string Sides::get_name(){
    return this->name;
}

int Sides::get_price(){
    return this->price;
}

char Sides::get_size(){
    return this-> size;
}

void Sides::set_name(string name){
    this->name = name;
}

void Sides::set_price(int price){
    this->price = price;
}

void Sides::set_size(char size){
    this->size = size;
}

