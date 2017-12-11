#ifndef TOPPING_H
#define TOPPING_H

#include <iostream>
#include <string>

using namespace std;

class Topping
{
    public:
        Topping(string name, int price, char type);
        string get_name(string name);
        int get_price(int price);
        char get_type(char type);
        void set_name();
        void set_price();
        void set_type();

    private:
        string name;
        int price;
        char type;
};

#endif // TOPPING_H
