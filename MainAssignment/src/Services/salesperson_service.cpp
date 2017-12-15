#include "salesperson_service.h"

Salesperson_service::Salesperson_service()
{
    //ctor
}

Vectors Salesperson_service::read_types(Vectors& vectors, string type){
    salesperson_repo.read_type(vectors, type);
    return vectors;
}

void Salesperson_service::get_base_price(Pizza& pizza){
    salesperson_repo.get_base_price(pizza);
}

void Salesperson_service::write_order(Orders& orders){
    salesperson_repo.write_order(orders);
}

void Salesperson_service::add_order(Orders &orders) {
    if(invalidNameException.isValidOrdersName(orders)) {
    salesperson_repo.write_order(orders);
    }
}
