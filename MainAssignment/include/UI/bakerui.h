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
        void main_menu(string location_name);
        void main_input_checker(char input);
        void main_input_checker(char input, string location_name);
        void print_locations();
        void print_orders(string& location_name, string& status);

    private:
        char input;
        Vectors vectors;
        Baker_service baker_service;

};

#endif // BAKERUI_H
