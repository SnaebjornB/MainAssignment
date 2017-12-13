#ifndef SALESPERSONUI_H
#define SALESPERSONUI_H

#include <iostream>

using namespace std;

class SalespersonUI
{
public:
    SalespersonUI();
    
    void main_menu();
    void main_input_checker(char input);
    
    void make_new_order_menu();
    void make_new_order_input_checker(char input);
    
    void change_order_menu();
    void change_order_input_checker(char input);
    
    void add_pizza_menu();
    void add_pizza_input_checkout(char input);
    
    void add_sides_menu();
    void add_sides_input_checkout(char input);
    
    void add_to_excisting_order_menu();
    void add_to_excisting_order_input_checkout(char input);
    
    void add_pizzasize_menu();
    void add_pizzasize_input_checkout(char input);
    
private:
    char input;
};

#endif // SALESPERSONUI_H
