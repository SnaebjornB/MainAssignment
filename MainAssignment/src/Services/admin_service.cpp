#include "admin_service.h"

Admin_Service::Admin_Service()
{
    //ctor
}

void Admin_Service::add_topping(Topping& topping){
    ///Validate topping(input)
    //Blah blah blah

    ///Send topping to DAta access layer
    admin_repo.write_topping(topping);
    //cout << car << endl;
}

Vectors Admin_Service::print_toppings(Vectors& vectors){
    admin_repo.read_topping(vectors);

    return vectors;
}

void Admin_Service::write_toppings(Vectors& vectors){
    admin_repo.put_back_topping(vectors);
}

void Admin_Service::erase_topping(Vectors& vectors, unsigned int num_of_line){
    admin_repo.erase_topping(vectors, num_of_line);
}
