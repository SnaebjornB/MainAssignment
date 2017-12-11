#include "topping.h"

Topping::Topping(string name, int price, char type){
    this->name = name;
    this->price = price;
    this->type = type;
}

string Topping::get_name(string name){
    return this->name;
}

int Topping::get_price(int price){
    return this->price;
}

char Topping::get_type(char type){
    return this->type;
}

void Topping::set_name(){
    this->name = name;
}

void Topping::set_price(){
    this->price = price;
}

void Topping::set_type(){
    this->type = type;
}
