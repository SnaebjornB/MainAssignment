#ifndef SALESPERSON_REPO_H
#define SALESPERSON_REPO_H

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "sides.h"
#include "menu_pizza.h"
#include "topping.h"
#include "vectors.h"
#include "pizza.h"
#include "orders.h"

using namespace std;

class Salesperson_repo
{
    public:
        Salesperson_repo();
        Vectors read_type(Vectors& vectors, string type);
        void get_base_price(Pizza& pizza);
        void write_order(Orders& orders, string location);
        Vectors read_locations(Vectors& vectors);
        Vectors read_orders(Vectors& vectors, string& location_name, string status);

    private:
        Topping topping;
        Sides sides;
        Menu_Pizza menu_pizza;
        Pizza pizza;
        Orders orders;

};

#endif // SALESPERSON_REPO_H
