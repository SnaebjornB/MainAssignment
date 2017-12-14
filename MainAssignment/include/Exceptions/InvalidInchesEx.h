//
//  InvalidInchesEx.hpp
//  final
//
//  Created by Arnbjörg Frímannsdóttir on 12/14/17.
//  Copyright © 2017 Arnbjörg Frímannsdóttir. All rights reserved.
//

#ifndef InvalidInchesEx_h
#define InvalidInchesEx_h

#include <string>
#include <iostream>
#include "topping.h"
using namespace std;

class InvalidInchesException {
public:
    InvalidInchesException();
    InvalidInchesException(string message);
    string getMessage();
    bool isvalidToppingInches(Topping topping);
private:
    string message;
};

#endif /* InvalidInchesEx_hpp */
