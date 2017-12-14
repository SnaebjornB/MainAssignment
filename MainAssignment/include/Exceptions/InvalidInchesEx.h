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
#include "menu_pizza.h"

using namespace std;

class InvalidInchesException {
public:
    InvalidInchesException();
    InvalidInchesException(string message);
    string getMessage();
    bool isvalidToppingInches(Topping& topping);
    bool isvalidMenuPizzaInches(Menu_Pizza& menu_pizza);
private:
    string message;
};

#endif /* InvalidInchesEx_hpp */
