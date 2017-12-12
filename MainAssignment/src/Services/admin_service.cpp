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

Vectors Admin_Service::read_types(Vectors& vectors, string type){
    cout << "2";
    admin_repo.read_type(vectors, type);
    return vectors;
}

void Admin_Service::write_type(Vectors& vectors, string type){
    admin_repo.put_back_type(vectors, type);
}

void Admin_Service::erase_type(Vectors& vectors, unsigned int num_of_line, string type){
    admin_repo.erase_type(vectors, num_of_line, type);
}

void Admin_Service::add_sides(Sides& sides){
    ///Validate topping(input)
    //Blah blah blah

    ///Send topping to DAta access layer
    admin_repo.write_sides(sides);
    //cout << car << endl;
}
