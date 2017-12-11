#ifndef ADMIN_REPO_H
#define ADMIN_REPO_H

#include <vector>
#include <iostream>
#include "topping.h"

using namespace std;

class Admin_Repo
{
    public:
        Admin_Repo();
        void print_toppings();

    private:
        vector<Topping> topping_list;
};

#endif // ADMIN_REPO_H
