#ifndef TOPPING_SERVICE_H
#define TOPPING_SERVICE_H

#include "topping.h"
#include "ToppingRepository.h"

class topping_service
{
    public:
        topping_service();
        void add_allowed_topping(Topping& topping);

    private:
        ToppingRepository topping_repo;
};

#endif // TOPPING_SERVICE_H
