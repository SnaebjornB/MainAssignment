#ifndef SALESPERSON_SERVICE_H
#define SALESPERSON_SERVICE_H

#include <vector>
#include <iostream>
#include "vectors.h"
#include "salesperson_repo.h"
#include "pizza.h"
#include "orders.h"

#include "InvalidNameEx.h"

using namespace std;

class Salesperson_service
{
    public:
        Salesperson_service();
        Vectors read_types(Vectors& vectors, string type);
        void get_base_price(Pizza& pizza);
        void write_order(Orders& orders);
    void add_order(Orders& orders);

    private:
        Salesperson_repo salesperson_repo;
        Pizza pizza;
    
        InvalidNameException invalidNameException;
};

#endif // SALESPERSON_SERVICE_H
