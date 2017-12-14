#include "sides.h"

Sides::Sides(){

}

Sides::Sides(string name, int price){
    this->name = name;
    this->price = price;
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

void Sides::set_helper(bool status){
    this->sides_helper = status;
}

void Sides::set_write_helper(bool status){
    this->write_helper = status;
}

ostream& operator << (ostream& out, Sides& sides){
    if (sides.sides_helper){
        out << sides.name;
    }
    else if (sides.write_helper){
        out << sides.name << ", " << sides.price << endl;
    }
    else{
        out << sides.name << ", " << sides.price;
    }

    return out;
}

istream& operator >> (istream& in, Sides& sides){
    getline(in, sides.name, ',') >> sides.price;
    in.ignore();

    return in;
}
