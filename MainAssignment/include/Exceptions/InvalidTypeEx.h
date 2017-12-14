//
//  InvalidTypeEx.hpp
//  final
//
//  Created by Arnbjörg Frímannsdóttir on 12/14/17.
//  Copyright © 2017 Arnbjörg Frímannsdóttir. All rights reserved.
//

#ifndef InvalidTypeEx_h
#define InvalidTypeEx_h

#include <string>
#include <iostream>
#include "topping.h"

using namespace std;

class InvalidTypeException {
public:
    InvalidTypeException();
    InvalidTypeException(string message);
    string getMessage();
    bool isvalidToppingType(Topping& topping);
private:
    string message;

};
#endif /* InvalidTypeEx_hpp */
