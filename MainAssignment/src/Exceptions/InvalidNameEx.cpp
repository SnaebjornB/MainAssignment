//
//  InvalidNameEx.cpp
//  final
//
//  Created by Arnbjörg Frímannsdóttir on 12/13/17.
//  Copyright © 2017 Arnbjörg Frímannsdóttir. All rights reserved.
//

#include "InvalidNameEx.h"

InvalidNameException::InvalidNameException() {
    
}

InvalidNameException::InvalidNameException(string message) {
    this->message = message;
};

string InvalidNameException::getMessage() {
    return this->message;
}

bool InvalidNameException::isvalidName(Topping& topping){
    string name = topping.get_name();
    for (unsigned int i = 0; i < name.length(); i++) {
        if (!(isalpha(name[i]) || name[i] == ' ')) {
            throw (InvalidNameException("invalid name!"));
        }
    }
    return true;
}
