#include "soda.h"

Soda::Soda(string name, int price, double size){
    this->name = name;
    this->price = price;
    this->size = size;
}

string Soda::get_name(){
    return this->name;
}

int Soda::get_price(){
    return this->price;
}

double Soda::get_size(){
    return this->size;
}

void Soda::set_name(string name){
    this->name = name;
}

void Soda::set_price(int price){
    this->price = price;
}

void Soda::set_size(double size){
    this->size = size;
}
