#ifndef ORDERS_H
#define ORDERS_H

#include <iostream>
#include <vector>
#include <string>
#include "sides.h"
#include "menu_pizza.h"
#include "pizza.h"

using namespace std;

class Orders
{
    public:
        Orders();

        bool get_baking_status();
        bool get_ready_status();
        bool get_paid_status();
        bool get_delivered_status();
        bool get_home_delivery_status();
        void set_baking_status(bool status);
        void set_ready_status(bool status);
        void set_paid_status(bool status);
        void set_delivered_status(bool status);
        void set_home_delivery_status(bool status);
        string get_comment();
        string get_address();
        string get_name();
        string get_phone_number();
        void set_comment(string change);
        void set_address(string change);
        void set_name(string change);
        void set_phone_number(string change);
        int get_total_price();
        void set_total_price(int price);
        void calculate_total();
        void set_helper(bool status);
        string get_name_of_place();
        void set_name_of_place(string change);
        void add_to_pizza_counter();
        void add_to_menu_pizza_counter();
        void add_to_sides_counter();
        friend ostream& operator << (ostream& out, Orders& orders);
        friend istream& operator >> (istream& in, Orders& orders);

        vector<Sides> sides_ordered;
        vector<Menu_Pizza> menuPizzas_ordered;
        vector<Pizza> otherPizzas_ordered;

    private:
        bool baking;
        bool ready;
        bool paid;
        bool delivered;
        bool home_delivery;
        bool orders_helper;
        string comment;
        string address;
        string name;
        string phone_number;
        string name_of_place;
        int total_price;
        int pizza_counter;
        int menu_pizza_counter;
        int sides_counter;


};

#endif // ORDERS_H
