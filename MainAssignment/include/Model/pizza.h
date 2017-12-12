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

    private:
        string name;
        int price;
        int size;
        bool pizza_helper;
        string topping_name;
};

#endif // PIZZA_H
