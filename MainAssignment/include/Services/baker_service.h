#ifndef BAKER_SERVICE_H
#define BAKER_SERVICE_H

#include <iostream>
#include <baker_repo.h>
#include <vector>
#include "vectors.h"

using namespace std;

class Baker_service
{
    public:
        Baker_service();
        Vectors read_locations(Vectors& vectors);
        Vectors read_orders(Vectors& vectors, string location_name);

    private:
        Baker_repo baker_repo;
};

#endif // BAKER_SERVICE_H
