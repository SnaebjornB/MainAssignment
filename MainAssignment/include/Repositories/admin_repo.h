#ifndef ADMIN_REPO_H
#define ADMIN_REPO_H

#include <vector>
#include <iostream>
#include "topping.h"
#include <fstream>
#include "vectors.h"

using namespace std;

class Admin_Repo
{
    public:
        Admin_Repo();
        void write_topping(Topping topping);
        Vectors read_topping(Vectors& vectors);
        void put_back_topping(Vectors& vectors);
        void erase_topping(Vectors& vectors, unsigned int num_of_line);


    private:
        Topping topping;

};

#endif // ADMIN_REPO_H
