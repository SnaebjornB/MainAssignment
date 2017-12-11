#include "topping_service.h"
#include "topping.h"

topping_service::topping_service()
{
    //ctor
}

void topping_service::add_allowed_topping(Topping& topping){
    ///Validate topping(input)
    //Blah blah blah

    ///Send topping to DAta access layer
    topping_repo.add_allowed_topping(topping);
    //cout << car << endl;
}
