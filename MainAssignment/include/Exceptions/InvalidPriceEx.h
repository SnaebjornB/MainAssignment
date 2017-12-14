//
//  InvalidPriceEx.hpp
//  main
//
//  Created by Arnbjörg Frímannsdóttir on 12/14/17.
//  Copyright © 2017 Arnbjörg Frímannsdóttir. All rights reserved.
//

#ifndef InvalidPriceEx_h
#define InvalidPriceEx_h

#include <string>
#include <iostream>
#include "topping.h"
#include "sides.h"
#include "menu_pizza.h"
using namespace std;

class InvalidPriceException {
public:
    InvalidPriceException();
    InvalidPriceException(string message);
    string getMessage();
    bool isvalidToppingPrice(Topping& topping);
    bool isvalidSidesPrice(Sides& sides);
    bool isvalidMenuPizzaPrice(Menu_Pizza& menu_pizza );
private:
    string message;
};

#endif /* InvalidPriceEx_hpp */
