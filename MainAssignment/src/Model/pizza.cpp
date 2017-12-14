#include "pizza.h"

Pizza::Pizza(){
    topping_counter = 0;
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

void Pizza::set_inches9(int inches9){
    this -> inches9 = inches9;
}
void Pizza::set_inches12(int inches12){
    this -> inches12 = inches12;
}
void Pizza::set_inches16(int inches16) {
    this -> inches16 = inches16;
}

void Pizza::set_helper(bool status){
    this->pizza_helper = status;
}

void Pizza::margaritaprice(char size_margarita) {
    price = 0;
    if (size_margarita == '1') {
        price = inches9;
        size = 9;
    }
    else if (size_margarita == '2') {
        price = inches12;
        size = 12;
    }
    else if (size_margarita == '3') {
        price = inches16;
        size = 16;
    }
}

void Pizza::set_size_helper(bool size_helper) {
    this->size_helper = size_helper;
}

void Pizza::set_total_price(){
    total_price = price;
    for(unsigned int i = 0; i < pizza_toppings.size(); i++){
        total_price += pizza_toppings[i].get_price();
    }
}

void Pizza::set_write_order_helper(bool status){
    this->write_order_helper = status;
}

void Pizza::add_to_topping_counter(){
    this->topping_counter++;
}

ostream& operator << (ostream& out, Pizza& pizza){
    if (pizza.size_helper) {
        if(pizza.pizza_helper){
            out << pizza.size << "\" " << "Pizza with:" << endl;
            for(unsigned int i = 0; i < pizza.pizza_toppings.size(); i++){
                out << pizza.pizza_toppings[i].get_name() << endl;
            }
        }
        else if(pizza.write_order_helper){
            out << pizza.name << ", " << pizza.price << " " << pizza.size << " ";
            for(unsigned int i = 0; i < pizza.pizza_toppings.size(); i++){
                out << pizza.pizza_toppings[i].get_name() << " ";
            }
            out << endl;
        }
        else{
            out << pizza.name << ", " << pizza.price << " " << pizza.size << " " << pizza.topping_counter << " ";
            for(unsigned int i = 0; i < pizza.pizza_toppings.size(); i++){
                out << pizza.pizza_toppings[i].get_name() << " ";
            }
        }
    }
    else {
        out << pizza.inches9 << " " << pizza.inches12 << " " << pizza.inches16;
    }
    return out;
}

istream& operator >> (istream& in, Pizza& pizza){
    if(pizza.size_helper) {
        getline(in, pizza.name, ',') >> pizza.price >> pizza.size;
        for (int i = 0;  in >> pizza.topping_name[i]; i++){
            in >> pizza.topping_name;
            pizza.pizza_toppings[i].set_name(pizza.topping_name);
        }
        in.ignore();
    }
    else {
        in >> pizza.inches9 >> pizza.inches12 >> pizza.inches16;
    }
    return in;
}


