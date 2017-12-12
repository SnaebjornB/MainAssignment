#ifndef VECTORS_H
#define VECTORS_H

#include <vector>
#include <iostream>
#include "topping.h"
#include "sides.h"

using namespace std;

class Vectors
{
    public:
        Vectors();
        vector<Topping> topping_list;
        vector<Sides> sides_list;



    private:

};

#endif // VECTORS_H
