#include "baker_service.h"

Baker_service::Baker_service()
{
    //ctor
}

Vectors Baker_service::read_locations(Vectors& vectors){
    baker_repo.read_locations(vectors);

    return vectors;
}

Vectors Baker_service::read_orders(Vectors& vectors, string location_name){
    baker_repo.read_orders(vectors, location_name);

    return vectors;
}
