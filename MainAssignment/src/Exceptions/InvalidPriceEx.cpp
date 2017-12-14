//
//  InvalidPriceEx.cpp
//  main
//
//  Created by Arnbjörg Frímannsdóttir on 12/14/17.
//  Copyright © 2017 Arnbjörg Frímannsdóttir. All rights reserved.
//

#include "InvalidPriceEx.h"

InvalidPriceException::InvalidPriceException() {
    
}

InvalidPriceException::InvalidPriceException(string message) {
    this->message = message;
};

string InvalidPriceException::getMessage() {
    return this->message;
}

bool InvalidPriceException::isvalidToppingPrice(Topping& topping) {
    if (topping.get_price() < 0) {
        throw (InvalidPriceException("invalid price!"));
    }
    return true;
}

bool InvalidPriceException::isvalidSidesPrice(Sides& sides) {
    if (sides.get_price() < 0) {
        throw (InvalidPriceException("invalid price!"));
    }
    return true;
}

bool InvalidPriceException::isvalidMenuPizzaPrice(Menu_Pizza& menu_pizza) {
    if (Menu_Pizza().get_price() < 0) {
        throw (InvalidPriceException("invalid price!"));
    }
    return true;
}

