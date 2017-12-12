#ifndef ADMIN_SERVICE_H
#define ADMIN_SERVICE_H

#include "topping.h"
#include <iostream>
#include "admin_repo.h"
#include <vector>
#include "vectors.h"
#include "sides.h"

using namespace std;

class Admin_Service
{
    public:
        Admin_Service();
        void add_topping(Topping& topping);
        void add_sides(Sides& sides);
        Vectors read_types(Vectors& vectors, string type);
        void write_type(Vectors& vectors, string type);
        void erase_type(Vectors& vectors, unsigned int num_of_line, string type);




    private:
        Admin_Repo admin_repo;
};

#endif // ADMIN_SERVICE_H
