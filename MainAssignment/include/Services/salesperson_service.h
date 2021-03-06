#ifndef SALESPERSON_SERVICE_H
#define SALESPERSON_SERVICE_H

#include <vector>
#include <iostream>
#include <string>
#include "vectors.h"
#include "salesperson_repo.h"
#include "pizza.h"
#include "orders.h"

#include "InvalidNameEx.h"
#include "InvalidPhonenumberEx.h"

using namespace std;

class Salesperson_service
{
    public:
        Salesperson_service();
        Vectors read_types(Vectors& vectors, string type);
        void get_base_price(Pizza& pizza);
        void write_order(Orders& orders, string location);
        void add_order(Orders& orders, string location);
        Vectors read_locations(Vectors& vectors);
        Vectors read_orders(Vectors& vectors, string& status, string location);

    private:
        Salesperson_repo salesperson_repo;
        Pizza pizza;

        InvalidNameException invalidNameException;
        InvalidPhonenumberException invalidPhonenumberException;
};

#endif // SALESPERSON_SERVICE_H
