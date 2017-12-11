#ifndef ADMINUI_H
#define ADMINUI_H

#include <iostream>

using namespace std;

class AdminUI
{
    public:
        AdminUI();
        void main_menu();
        void input_checker(char input);

    private:
        char input;
};

#endif // ADMINUI_H
