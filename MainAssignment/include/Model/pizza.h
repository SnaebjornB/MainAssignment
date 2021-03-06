#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
#include <vector>
#include "topping.h"
#include <fstream>

using namespace std;

class Pizza
{
public:
    Pizza();
    Pizza(string name, int price, int size);
    vector<Topping> pizza_toppings;
    void set_name(string name);
    void set_price(int price);
    void set_size(int size);
    string get_name();
    int get_price();
    int get_size();
    void set_helper(bool status);
    friend ostream& operator << (ostream& out, Pizza& pizza);
    friend istream& operator >> (istream& in, Pizza& pizza);
    void margaritaprice(char size_margarita);
    void set_size_helper(bool size_helper);
    void set_margarita_price(bool margarita_price);
    int set_total_price();
    void set_inches9(int inches9);
    void set_inches12(int inches12);
    void set_inches16(int inches16);
    void set_write_order_helper(bool status);
    void add_to_topping_counter();
private:
    string name;
    int price;
    int size;
    bool pizza_helper;
    string topping_name;
    bool size_helper;
    int inches9;
    int inches12;
    int inches16;
    bool margarita_price;
    int total_price;
    bool write_order_helper;
    int topping_counter;
    Topping topping;
};

#endif // PIZZA_H
