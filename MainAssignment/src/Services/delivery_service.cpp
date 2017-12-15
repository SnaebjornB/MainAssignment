#include "delivery_service.h"

Delivery_service::Delivery_service()
{
    //ctor
}

Vectors Delivery_service::read_locations(Vectors& vectors){
    delivery_repo.read_locations(vectors);

    return vectors;
}

Vectors Delivery_service::read_orders(Vectors& vectors, string& status, string location){
    delivery_repo.read_orders(vectors, location, status);

    return vectors;
}

void Delivery_service::check_in_making(Vectors& vectors, string location, string current_status, string next_status){
    delivery_repo.change_order_status(vectors, location, current_status, next_status);
}
