#ifndef BAKERUI_H
#define BAKERUI_H

#include <iostream>
#include "baker_service.h"
#include <string>

using namespace std;

class BakerUI
{
    public:
        BakerUI();
        void location();
        void main_menu();
        void main_input_checker(char input);
        void main_input_checker(char input, string location_name);
        void print_locations();
        Vectors print_orders(Vectors& vectors, string status);
        void print_next_order(Vectors& vectors, string status);
        void check_in_making(int choice, Vectors& vectors);

    private:
        char input;
        Vectors vectors;
        Baker_service baker_service;
        string location_name;

};

#endif // BAKERUI_H
