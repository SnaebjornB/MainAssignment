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

    if (pizza.margarita_price) {
        if(pizza.pizza_helper){
            out << pizza.size << "\" " << "Pizza with:" << endl;
            for(unsigned int i = 0; i < pizza.pizza_toppings.size(); i++){
                out << pizza.pizza_toppings[i].get_name() << endl;
            }
        }
        else{
            out << pizza.name << ", " << pizza.price << " " << pizza.size << " ";
            for(unsigned int i = 0; i < pizza.pizza_toppings.size(); i++){
                out << pizza.pizza_toppings[i].get_name() << " ";
            }
            out << endl;
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

int Pizza::total_price(int size_margarita) {
    int totalprice = 0;
    if (size_margarita == 1) {
        totalprice = inches9;
    }
    else if (size_margarita == 2) {
        totalprice = inches12;
    }
    else if (size_margarita == 3) {
        totalprice = inches16;
    }
    for (unsigned int i = 0 ; i < pizza_toppings.size() ; i++ ) {
        totalprice += pizza_toppings[i].get_price();
    }
    return totalprice;
}

void Pizza::set_size_helper(bool size_helper) {
    this->size_helper = size_helper;
}

void Pizza::set_margarita_price(bool margarita_price) {
    this ->margarita_price = margarita_price;
}


