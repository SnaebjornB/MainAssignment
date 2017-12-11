#ifndef TOPPINGREPOSITORY_H
#define TOPPINGREPOSITORY_H
#include "topping.h"
#include <fstream>

class ToppingRepository
{
    public:
        ToppingRepository();
        void add_allowed_topping(Topping& topping);

    private:
};

#endif // TOPPINGREPOSITORY_H
