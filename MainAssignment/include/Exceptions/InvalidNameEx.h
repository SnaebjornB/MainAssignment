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
using namespace std;

class InvalidNameException {
public:
    InvalidNameException();
    InvalidNameException(string message);
    string getMessage();
    bool isvalidName(Topping& topping);
private:
    string message;

};

#endif /* InvalidNameEx_hp */
