#ifndef ORDERS_H
#define ORDERS_H

#include <iostream>
#include <vector>
#include <string>
#include "sides.h"
#include "menu_pizza.h"
#include "pizza.h"

using namespace std;

class Orders
{
    public:
        Orders();

        vector<Sides> sides_ordered;
        vector<Menu_Pizza> menuPizzas_ordered;
        vector<Pizza> otherPizzas_ordered;

    private:
        bool baking;
        bool ready;
        bool paid;
        bool delivered;
        bool home_delivery;
        string comment;
        string address;
        string name;
        string phone_number;
        int total_price;


};

#endif // ORDERS_H
