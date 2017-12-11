#ifndef ADMINUI_H
#define ADMINUI_H

#include <iostream>
#include "admin_repo.h"

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
        void add_topping();

    private:
        char input;
        Admin_Repo admin_repo;
};

#endif // ADMINUI_H
