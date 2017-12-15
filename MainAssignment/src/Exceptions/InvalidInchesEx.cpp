//
//  InvalidInchesEx.cpp
//  final
//
//  Created by Arnbjörg Frímannsdóttir on 12/14/17.
//  Copyright © 2017 Arnbjörg Frímannsdóttir. All rights reserved.
//

#include "InvalidInchesEx.h"

InvalidInchesException::InvalidInchesException() {
    
}

InvalidInchesException::InvalidInchesException(string message) {
    this->message = message;
};

string InvalidInchesException::getMessage() {
    return this->message;
}

bool InvalidInchesException::isvalidToppingInches(Topping& topping) {
    int  size = topping.get_size();
    if (!(size == 9 || size == 12 || size == 16)) {
        throw (InvalidInchesException("invalid size!"));
    }
    return true;
}

bool InvalidInchesException::isvalidMenuPizzaInches(Menu_Pizza& menu_pizza) {
    int  size = menu_pizza.get_size();
    if (!(size == 9 || size == 12 || size == 16)) {
        throw (InvalidInchesException("invalid size!"));
    }
    return true;
}
