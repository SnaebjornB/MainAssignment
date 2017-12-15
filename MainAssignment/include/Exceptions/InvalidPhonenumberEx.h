

#ifndef InvalidPhonenumberEx_h
#define InvalidPhonenumberEx_h

#include <string>
#include <iostream>
#include "orders.h"

using namespace std;

class InvalidPhonenumberException {
public:
    InvalidPhonenumberException();
    InvalidPhonenumberException(string message);
    string getMessage();
    bool isvalidOrdersPhonenumber(Orders& orders);
private:
    string message;
};

#endif /* InvalidPhonenumberEx_hpp */
