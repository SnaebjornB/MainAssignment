#ifndef SODA_H
#define SODA_H

#include <iostream>
#include <string>

using namespace std;

class Soda
{
    public:
        Soda(string name, int price, double size);
        void set_name(string name);
        void set_price(int price);
        void set_size(double size);
        string get_name();
        int get_price();
        double get_size();

    private:
        string name;
        int price;
        double size;
};

#endif // SODA_H
