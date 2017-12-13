#ifndef SALESPERSON_REPO_H
#define SALESPERSON_REPO_H

#include <fstream>
#include <vector>
#include <iostream>
#include "sides.h"
#include "menu_pizza.h"
#include "topping.h"
#include "vectors.h"
#include "pizza.h"

using namespace std;

class Salesperson_repo
{
    public:
        Salesperson_repo();
        Vectors read_type(Vectors& vectors, string type);
        void get_base_price(Pizza& pizza);

    private:
        Topping topping;
        Sides sides;
        Menu_Pizza menu_pizza;
        Pizza pizza;

};

#endif // SALESPERSON_REPO_H
