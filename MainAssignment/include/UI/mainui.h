#ifndef MAINUI_H
#define MAINUI_H

#include <iostream>
#include "adminui.h"
#include "bakerui.h"
#include "salespersonui.h"
#include "deliveryui.h"

using namespace std;


class MainUI
{
    public:
        MainUI();
        void main_menu();
        void input_checker(char input);

    private:
        char input;
        AdminUI adminui;
        BakerUI bakerui;
        SalespersonUI salesui;
        DeliveryUI deliveryui;
};

#endif // MAINUI_H
