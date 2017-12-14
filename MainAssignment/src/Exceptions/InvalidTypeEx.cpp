//
//  InvalidTypeEx.cpp
//  final
//
//  Created by Arnbjörg Frímannsdóttir on 12/14/17.
//  Copyright © 2017 Arnbjörg Frímannsdóttir. All rights reserved.
//

#include "InvalidTypeEx.h"

InvalidTypeException::InvalidTypeException() {

}

InvalidTypeException::InvalidTypeException(string message) {
    this->message = message;
};

string InvalidTypeException::getMessage() {
    return this->message;
}

bool InvalidTypeException::isvalidToppingType(Topping topping) {
    char type = topping.get_type();
    if (isdigit(type) || type != 'm' || type != 'v' || type != 's' || type != 'c') {
        throw (InvalidTypeException("invalid type!"));
    }
    return true;
}
