#ifndef SIDES_H
#define SIDES_H

#include <iostream>
#include <string>

using namespace std;

class Sides
{
    public:
        Sides();
        Sides(string name, int price);
        string get_name();
        int get_price();
        char get_size();
        void set_name(string name);
        void set_price(int price);
        void set_size(char size);
        void set_helper(bool status);
        void set_write_helper(bool status);
        friend ostream& operator << (ostream& out, Sides& sides);
        friend istream& operator >> (istream& in, Sides& sides);

    private:
        string name;
        int price;
        char size;
        bool sides_helper;
        bool write_helper;
};

#endif // SIDES_H
