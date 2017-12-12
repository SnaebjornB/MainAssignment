#include "pizza.h"

Pizza::Pizza(){

}

Pizza::Pizza(string name, int price, int size){
    this->name = name;
    this->price = price;
    this->size = size;
}

void Pizza::set_name(string name){
    this->name = name;
}

void Pizza::set_price(int price){
    this->price = price;
}

void Pizza::set_size(int size){
    this->size = size;
}

string Pizza::get_name(){
    return this->name;
}

int Pizza::get_price(){
    return this->price;
}

int Pizza::get_size(){
    return this->size;
}

void Pizza::set_helper(bool status){
    this->pizza_helper = status;
}

ostream& operator << (ostream& out, Pizza& pizza){
    if(pizza.pizza_helper){
        out << pizza.size << "\" " << "Pizza with:" << endl;
        for(unsigned int i = 0; i < pizza.toppings.size(); i++){
            out << pizza.toppings[i].get_name() << endl;
        }
    }
    else{
        out << pizza.name << ", " << pizza.price << " " << pizza.size << " ";
        for(unsigned int i = 0; i < pizza.toppings.size(); i++){
            out << pizza.toppings[i].get_name() << " ";
        out << endl;
        }
    }
    return out;
}

istream& operator >> (istream& in, Pizza& pizza){
    getline(in, pizza.name, ',') >> pizza.price >> pizza.size;
    for (int i = 0; !'\n'; i++){
        in >> pizza.topping_name;
        pizza.toppings[i].set_name(pizza.topping_name);
    }
    in.ignore();
    return in;
}
