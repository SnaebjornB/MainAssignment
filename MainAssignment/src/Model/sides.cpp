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

void set_helper(bool status){
    this->sides_helper = status;
}

ostream& operator << (ostream& out, Sides sides){
    if (sides_helper){
        out << sides.name << endl;
    }
    else{
        out << sides.name << ", " << sides.price;
    }
}

istream& operator >> (istream& in, Sides sides){
    getline(in, sides.name, ',') >> sides.price;
}
