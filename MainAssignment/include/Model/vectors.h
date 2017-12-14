#ifndef VECTORS_H
#define VECTORS_H

#include <vector>
#include <iostream>
#include "topping.h"
#include "sides.h"
#include "menu_pizza.h"
#include <string>
#include "orders.h"

using namespace std;

class Vectors
{
    public:
        Vectors();
        vector<Topping> topping_list;
        vector<Sides> sides_list;
        vector<Menu_Pizza> pizza_menu_list;
        vector<string> locations_list;
        vector<Orders> orders_list;



    private:

};

#endif // VECTORS_H
