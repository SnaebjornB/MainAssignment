#ifndef SALESPERSONUI_H
#define SALESPERSONUI_H

#include <iostream>

using namespace std;

class SalespersonUI
{
    public:
        SalespersonUI();
        void main_menu();
        void input_checker(char input);

    private:
        char input;
};

#endif // SALESPERSONUI_H
