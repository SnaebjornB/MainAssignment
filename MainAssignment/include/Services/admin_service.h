#ifndef ADMIN_SERVICE_H
#define ADMIN_SERVICE_H

#include "topping.h"
#include <iostream>
#include "admin_repo.h"
#include <vector>
#include "vectors.h"

using namespace std;

class Admin_Service
{
    public:
        Admin_Service();
        void add_topping(Topping& topping);
        Vectors print_toppings(Vectors& vectors);
        void write_toppings(Vectors& vectors);
        void erase_topping(Vectors& vectors, unsigned int num_of_line);



    private:
        Admin_Repo admin_repo;
};

#endif // ADMIN_SERVICE_H
