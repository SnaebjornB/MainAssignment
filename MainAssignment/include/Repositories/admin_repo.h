#ifndef ADMIN_REPO_H
#define ADMIN_REPO_H

#include <vector>
#include <iostream>
#include "topping.h"
#include <fstream>
#include "vectors.h"
#include "sides.h"
#include "pizza.h"

using namespace std;

class Admin_Repo
{
    public:
        Admin_Repo();
        void write_topping(Topping topping);
        void write_sides(Sides& sides);
        void write_pizza(Pizza& pizza);
        Vectors read_type(Vectors& vectors, string type);
        void put_back_type(Vectors& vectors, string type);
        void erase_type(Vectors& vectors, unsigned int num_of_line, string type);



    private:
        Topping topping;
        Sides sides;

};

#endif // ADMIN_REPO_H
