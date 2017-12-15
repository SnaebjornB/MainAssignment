#include "baker_service.h"

Baker_service::Baker_service()
{
    //ctor
}

Vectors Baker_service::read_locations(Vectors& vectors){
    baker_repo.read_locations(vectors);

    return vectors;
}

Vectors Baker_service::read_orders(Vectors& vectors, string& status, string location){
    baker_repo.read_orders(vectors, location, status);

    return vectors;
}

void Baker_service::set_private_location_name(string location_name){
    this->private_location_name = location_name;
}

string Baker_service::get_private_location_name(){
    return this->private_location_name;
}

void Baker_service::check_in_making(Vectors& vectors, string location, string current_status, string next_status){
    baker_repo.change_order_status(vectors, location, current_status, next_status);
}
