#ifndef BAKERUI_H
#define BAKERUI_H

#include <iostream>

using namespace std;

class BakerUI
{
    public:
        BakerUI();
        void location();
        void main_menu();
        void main_input_checker(char input);


    private:
        char input;
};

#endif // BAKERUI_H
