#ifndef DELIVERYUI_H
#define DELIVERYUI_H

#include <iostream>

using namespace std;

class DeliveryUI
{
public:
    DeliveryUI();
    void location();
    void main_menu();
    void main_input_checker(char input);
private:
    char input;
    string location_name;
};

#endif // DELIVERYUI_H
