#ifndef TOPPING_H
#define TOPPING_H

#include <iostream>
#include <string>

using namespace std;

class Topping
{
    public:
        Topping(string name, int price, char type);
        string get_name();
        int get_price();
        char get_type();
        void set_name(string name);
        void set_price(int price);
        void set_type(char type);

    private:
        string name;
        int price;
        char type;
};

#endif // TOPPING_H
