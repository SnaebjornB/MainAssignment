#ifndef MENU_PIZZA_H
#define MENU_PIZZA_H

#include <iostream>
#include <string>

using namespace std;

class Menu_Pizza
{
    public:
        Menu_Pizza();
        Menu_Pizza(string name, int price, int size);
        string get_name();
        int get_price();
        int get_size();
        void set_name(string name);
        void set_price(int price);
        void set_size(int size);
        void set_helper(bool status);
        friend ostream& operator << (ostream& out, Menu_Pizza& menu_pizza);
        friend istream& operator >> (istream& in, Menu_Pizza& menu_pizza);
        void set_print_helper(bool status);

    private:
        string name;
        int price;
        bool menu_pizza_helper;
        bool print_helper;
        int size;
};

#endif // MENU_PIZZA_H
