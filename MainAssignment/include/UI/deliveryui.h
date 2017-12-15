#ifndef DELIVERYUI_H
#define DELIVERYUI_H

#include <iostream>
#include "delivery_service.h"
#include <string>

using namespace std;

class DeliveryUI
{
public:
    DeliveryUI();
    void location();
    void main_menu();
    void main_input_checker(char input);
    void print_all_orders();
    void print_locations();
    void print_ready_orders();
    void print_specific_order();
    void check_order_paid();
    void check_order_delivered();

private:
    char input;
    Vectors vectors;
    Delivery_service delivery_service;
    string location_name;
    vector<Orders> current_order;

};

#endif // DELIVERYUI_H
