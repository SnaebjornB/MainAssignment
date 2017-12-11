#ifndef DELIVERYUI_H
#define DELIVERYUI_H

#include <iostream>

using namespace std;

class DeliveryUI
{
    public:
        DeliveryUI();
        void main_menu();
        void input_checker(char input);
    private:
        char input;
};

#endif // DELIVERYUI_H
