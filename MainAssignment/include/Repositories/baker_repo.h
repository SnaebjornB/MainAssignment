#ifndef BAKER_REPO_H
#define BAKER_REPO_H

#include <vector>
#include <iostream>
#include <fstream>
#include "vectors.h"
#include "orders.h"
#include "pizza.h"
#include "menu_pizza.h"
#include "sides.h"


using namespace std;

class Baker_repo
{
    public:
        Baker_repo();
        Vectors read_locations(Vectors& vectors);
        Vectors read_orders(Vectors& vectors, string& location_name, string& status);
        Vectors change_order_status(Vectors& vectors, string& location_name, string& current_status, string next_status);


    private:
        Topping topping;
        Sides sides;
        Menu_Pizza menu_pizza;
        Pizza pizza;
        Orders orders;

};

#endif // BAKER_REPO_H
