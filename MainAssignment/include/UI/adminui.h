#ifndef ADMINUI_H
#define ADMINUI_H

#include <iostream>

using namespace std;

class AdminUI
{
    public:
        AdminUI();
        void main_menu();
        void main_input_checker(char input);
        void topping_menu();
        void topping_input_checker(char input);
        void sides_menu();
        void sides_input_checker(char input);
        void pizza_menu();
        void pizza_input_checker(char input);
        void location_menu();
        void location_input_checker(char input);
        void pizzamenu_menu();
        void pizzamenu_input_checker(char input);

    private:
        char input;
};

#endif // ADMINUI_H
