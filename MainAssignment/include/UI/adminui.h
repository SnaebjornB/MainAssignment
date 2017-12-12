#ifndef ADMINUI_H
#define ADMINUI_H

#include <iostream>
#include "admin_repo.h"
#include "admin_service.h"
#include "vectors.h"
#include "sides.h"

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
        Topping create_topping();
        void print_toppings();
        Sides create_sides();
        void print_sides();

    private:
        char input;
        Admin_Repo admin_repo;
        Admin_Service admin_service;
        Vectors vectors;

};

#endif // ADMINUI_H
