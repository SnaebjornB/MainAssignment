#ifndef SODA_H
#define SODA_H

#include <iostream>
#include <string>

using namespace std;

class Soda
{
    public:
        Soda(string name, int price, double size);

    private:
        string name;
        int price;
        double size;
};

#endif // SODA_H
