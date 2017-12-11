#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
#include <vector>
#include "topping.h"

using namespace std;

class Pizza
{
    public:
        Pizza(string name, int price, int size);

    private:
        string name;
        int price;
        vector<Topping> toppings;
        int size;
};

#endif // PIZZA_H
