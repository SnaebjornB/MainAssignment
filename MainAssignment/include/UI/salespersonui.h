#ifndef SALESPERSONUI_H
#define SALESPERSONUI_H

#include <iostream>
#include "pizza.h"
#include "orders.h"
#include "sides.h"
#include "menu_pizza.h"
#include "salesperson_service.h"
#include "vectors.h"

using namespace std;

class SalespersonUI
{
public:
    SalespersonUI();

    void main_menu();
    void main_input_checker(char input);

    void make_new_order_menu();
    void make_new_order_input_checker(char input);

    void add_pizza_menu();
    void add_pizza_input_checkout(char input);

    void add_sides_menu();
    void add_sides_input_checkout(char input);

    void add_to_existing_order_menu();
    void add_to_existing_order_input_checkout(char input);

    void add_pizzasize_menu();
    void add_pizzasize_input_checkout(char input);

    Orders order_prompt();
    void location();

    void print_locations();
    void add_to_order();

    void add_menu_pizza();
    void add_sides();

    void check_order_as_paid();
    void finish_order();

    void add_to_order_menu();
    void add_to_order_input_checker(char input);

    Vectors print_sides(Vectors& vectors, string type);
    Vectors print_pizza_menu(Vectors& vectors, string type);
    Vectors print_toppings(Vectors& vectors, string type, char input);


private:
    char input;
    Pizza pizza;
    Salesperson_service salesperson_service;
    Orders orders;
    Vectors vectors;
    vector<Orders> current_order;
    string location_name;
};

#endif // SALESPERSONUI_H
