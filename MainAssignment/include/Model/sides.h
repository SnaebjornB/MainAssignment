#ifndef SIDES_H
#define SIDES_H

#include <iostream>
#include <string>

using namespace std;

class Sides
{
    public:
        Sides(string name, int price, char size);
        string get_name();
        int get_price();
        char get_size();
        void set_name(string name);
        void set_price(int price);
        void set_size(char size);

    private:
        string name;
        int price;
        char size;
};

#endif // SIDES_H
