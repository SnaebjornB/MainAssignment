#ifndef BAKER_REPO_H
#define BAKER_REPO_H

#include <vector>
#include <iostream>
#include <fstream>
#include "vectors.h"

using namespace std;

class Baker_repo
{
    public:
        Baker_repo();
        Vectors read_locations(Vectors& vectors);
        Vectors read_orders(Vectors& vectors, string location_name);


    private:
};

#endif // BAKER_REPO_H
