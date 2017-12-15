#ifndef DELIVERY_SERVICE_H
#define DELIVERY_SERVICE_H

#include <iostream>
#include "delivery_repo.h"
#include <vector>
#include "vectors.h"

class Delivery_service
{
    public:
        Delivery_service();
        Vectors read_locations(Vectors& vectors);
        Vectors read_orders(Vectors& vectors, string& status, string location);
        void check_in_making(Vectors& vectors, string location, string current_status, string next_status);

    private:

        string private_location_name;
        Delivery_repo delivery_repo;
};

#endif // DELIVERY_SERVICE_H
