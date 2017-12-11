#ifndef BAKERUI_H
#define BAKERUI_H

#include <iostream>

using namespace std;

class BakerUI
{
    public:
        BakerUI();
        void main_menu();
        void input_checker(char input);


    private:
        char input;
};

#endif // BAKERUI_H
