//
//  InvalidNameEx.hpp
//  final
//
//  Created by Arnbjörg Frímannsdóttir on 12/13/17.
//  Copyright © 2017 Arnbjörg Frímannsdóttir. All rights reserved.
//

#ifndef InvalidNameEx_h
#define InvalidNameEx_h

#include <string>
#include <iostream>
#include "topping.h"
#include "sides.h"
using namespace std;

class InvalidNameException {
public:
    InvalidNameException();
    InvalidNameException(string message);
    string getMessage();
    bool isvalidToppingName(Topping& topping);
    bool isvalidSidesName(Sides& sides);
private:
    string message;

};

#endif /* InvalidNameEx_hp */
