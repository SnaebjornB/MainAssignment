#ifndef TOPPING_H
#define TOPPING_H

#include <iostream>
#include <string>

using namespace std;

class Topping
{
    public:
        Topping(string name, int price, char type, int size);
        string get_name();
        int get_price();
        char get_type();
        void set_name(string name);
        void set_price(int price);
        void set_type(char type);
        friend ostream& operator << (ostream& out, Topping& topping);
        void set_topping_helper(bool status);
        friend istream& operator >> (istream& in, Topping& topping);

    private:
        string name;
        int price;
        char type;
        int pizza_size;
        bool topping_helper;
};

#endif // TOPPING_H
