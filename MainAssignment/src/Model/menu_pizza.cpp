#include "menu_pizza.h"

Menu_Pizza::Menu_Pizza(){
    //ctor
}

Menu_Pizza::Menu_Pizza(string name, int price, int size){
    this->name = name;
    this->price = price;
}

void Menu_Pizza::set_helper(bool status){
    this->menu_pizza_helper = status;
}

string Menu_Pizza::get_name(){
    return this->name;
}

int Menu_Pizza::get_price(){
    return this->price;
}

int Menu_Pizza::get_size(){
    return this->size;
}

void Menu_Pizza::set_name(string name){
    this->name = name;
}

void Menu_Pizza::set_price(int price){
    this->price = price;
}

void Menu_Pizza::set_size(int size){
    this->size = size;
}

ostream& operator << (ostream& out, Menu_Pizza& menu_pizza){
    if (menu_pizza.menu_pizza_helper){
        out << menu_pizza.name;
    }
    else{
        out << menu_pizza.name << ", " << menu_pizza.price << endl;
    }
    return out;
}

istream& operator >> (istream& in, Menu_Pizza& menu_pizza){
    getline(in, menu_pizza.name, ',') >> menu_pizza.price;
    in.ignore();

    return in;

}
