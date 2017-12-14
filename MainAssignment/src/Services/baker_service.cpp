#include "baker_service.h"

Baker_service::Baker_service()
{
    //ctor
}

Vectors Baker_service::read_locations(Vectors& vectors){
    baker_repo.read_locations(vectors);

    return vectors;
}

Vectors Baker_service::read_orders(Vectors& vectors, string& status){
    string location_name = get_private_location_name();
    baker_repo.read_orders(vectors, location_name, status);

    return vectors;
}

void Baker_service::set_private_location_name(string location_name){
    this->private_location_name = location_name;
}

string Baker_service::get_private_location_name(){
    return this->private_location_name;
}

