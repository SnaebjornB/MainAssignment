#ifndef BAKER_SERVICE_H
#define BAKER_SERVICE_H

#include <iostream>
#include "baker_repo.h"
#include <vector>
#include "vectors.h"

using namespace std;

class Baker_service
{
    public:
        Baker_service();
        Vectors read_locations(Vectors& vectors);
        Vectors read_orders(Vectors& vectors, string& status, string location);
        void check_in_making(Vectors& vectors, string location, string current_status, string next_status);

    private:
        Baker_repo baker_repo;
        string private_location_name;
};

#endif // BAKER_SERVICE_H
