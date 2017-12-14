#ifndef BAKER_REPO_H
#define BAKER_REPO_H

#include <vector>
#include <iostream>
#include <fstream>
#include "vectors.h"
#include "orders.h"


using namespace std;

class Baker_repo
{
    public:
        Baker_repo();
        Vectors read_locations(Vectors& vectors);
        Vectors read_orders(Vectors& vectors, string& location_name, string& status);


    private:
        Orders orders;
};

#endif // BAKER_REPO_H
