//
//  InvalidPhonenumberEx.cpp
//  main
//
//  Created by Arnbjörg Frímannsdóttir on 12/15/17.
//  Copyright © 2017 Arnbjörg Frímannsdóttir. All rights reserved.
//

#include "InvalidPhonenumberEx.h"

InvalidPhonenumberException::InvalidPhonenumberException() {
    
}

InvalidPhonenumberException::InvalidPhonenumberException(string message) {
    this->message = message;
};

string InvalidPhonenumberException::getMessage() {
    return this->message;
}

bool InvalidPhonenumberException::isvalidOrdersPhonenumber(Orders& orders) {
    string number = orders.get_phone_number();
    if (!(number.length() == 7)) {
        throw (InvalidPhonenumberException("invalid phone number!"));
    }
    
    for (int i = 0 ;  i < number.length() ; i++) {
        if (!isdigit(number[i])) {
            throw (InvalidPhonenumberException("invalid phone number!"));
        }
    }
    return true;
}
