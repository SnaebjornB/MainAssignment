#include "topping.h"

Topping::Topping(string name, int price, char type){
    this->name = name;
    this->price = price;
    this->type = type;
}

string Topping::get_name(){
    return this->name;
}

int Topping::get_price(){
    return this->price;
}

char Topping::get_type(){
    return this->type;
}

void Topping::set_name(string name){
    this->name = name;
}

void Topping::set_price(int price){
    this->price = price;
}

void Topping::set_type(char type){
    this->type = type;
}
