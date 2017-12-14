#include "topping.h"

Topping::Topping(){

}

Topping::Topping(string name, int price, char type, int size){
    this->name = name;
    this->price = price;
    this->type = type;
    this->pizza_size = size;
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

int Topping::get_size(){
    return this->pizza_size;
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

void Topping::set_size(int size){
    this->pizza_size = size;
}

void Topping::set_helper(bool status){
    topping_helper = status;
}

ostream& operator << (ostream& out, Topping& topping){
    if(topping.topping_helper){
        out << topping.pizza_size << "\" " << topping.name;
    }
    else{
        out << topping.name << ", " << topping.pizza_size << " " << topping.price << " " << topping.type << endl;
    }

    return out;
}

istream& operator >> (istream& in, Topping& topping){

    getline(in, topping.name, ',') >> topping.pizza_size >> topping.price >> topping.type;
    in.ignore();

    return in;
}
