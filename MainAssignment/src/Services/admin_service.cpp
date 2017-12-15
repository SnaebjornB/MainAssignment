#include "admin_service.h"

Admin_Service::Admin_Service()
{
    //ctor
}

void Admin_Service::add_topping(Topping topping){
    if(invalidNameException.isvalidToppingName(topping) &&
       invalidInchesException.isvalidToppingInches(topping) &&
       invalidTypeException.isvalidToppingType(topping) &&
       invalidPriceException.isvalidToppingPrice(topping)) {

        admin_repo.write_topping(topping);
    }
    //cout << car << endl;
}

Vectors Admin_Service::read_types(Vectors& vectors, string type){
    admin_repo.read_type(vectors, type);
    return vectors;
}

void Admin_Service::write_type(Vectors& vectors, string type ){
    if (true) {
        admin_repo.put_back_type(vectors, type);
    }
}

void Admin_Service::erase_type(Vectors& vectors, unsigned int num_of_line, string type){
    admin_repo.erase_type(vectors, num_of_line, type);
}

void Admin_Service::add_sides(Sides sides){
    if (invalidNameException.isvalidSidesName(sides) &&
        invalidPriceException.isvalidSidesPrice(sides)){

        admin_repo.write_sides(sides);
    }
}

void Admin_Service::add_menu_pizza(Menu_Pizza& menu_pizza){
    if(invalidPriceException.isvalidMenuPizzaPrice(menu_pizza) &&
       invalidNameException.isvalidMenuPizzaName(menu_pizza) &&
       invalidInchesException.isvalidMenuPizzaInches(menu_pizza)) {

           admin_repo.write_menu_pizza(menu_pizza);
    }
}

void Admin_Service::add_location(string location){
    if(invalidNameException.isvalidLocationName(location)) {
        admin_repo.write_location(location);
    }

}

void Admin_Service::add_margarita_price(Pizza& pizza) {
    admin_repo.write_price_margarita(pizza);
}

