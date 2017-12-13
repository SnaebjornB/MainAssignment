#include "orders.h"

Orders::Orders()
{
    orders_helper = true;
    baking = false;
    ready = false;
    paid= false;
    delivered= false;
    home_delivery= false;
    comment[0] = '\0';
    address[0] = '\0';
    name[0] = '\0';
    phone_number[0] = '\0';
    total_price = 0;
}

bool Orders::get_baking_status(){
    return this->baking;
}

bool Orders::get_ready_status(){
    return this->ready;
}

bool Orders::get_paid_status(){
    return this->paid;
}

bool Orders::get_delivered_status(){
    return this->delivered;
}

bool Orders::get_home_delivery_status(){
    return this->home_delivery;
}

void Orders::set_baking_status(bool status){
    this->baking = status;
}

void Orders::set_ready_status(bool status){
    this->ready = status;
}

void Orders::set_paid_status(bool status){
    this->paid = status;
}

void Orders::set_delivered_status(bool status){
    this->delivered = status;
}

void Orders::set_home_delivery_status(bool status){
    this->home_delivery = status;
}

string Orders::get_comment(){
    return this->comment;
}

string Orders::get_address(){
    return this->address;
}

string Orders::get_name(){
    return this->name;
}

string Orders::get_phone_number(){
   return this->phone_number;
}

string Orders::get_name_of_place(){
    return this->name_of_place;
}

void Orders::set_comment(string change){
    this->comment = change;
}

void Orders::set_address(string change){
    this->address = change;
}

void Orders::set_name(string change){
    this->name = change;
}

void Orders::set_phone_number(string change){
    this->phone_number = change;
}

void Orders::set_name_of_place(string change){
    this->name_of_place = change;
}

int Orders::get_total_price(){
    return this->total_price;
}

void Orders::set_total_price(int price){
    this->total_price = price;
}

void Orders::calculate_total(){
    for(unsigned int i = 0; i < sides_ordered.size(); i++){
        total_price += sides_ordered[i].get_price();
    }
    for(unsigned int i = 0; i < menuPizzas_ordered.size(); i++){
        total_price += menuPizzas_ordered[i].get_price();
    }
    for(unsigned int i = 0; i < otherPizzas_ordered.size(); i++){
        total_price += otherPizzas_ordered[i].get_price();
    }
}

void Orders::set_helper(bool status){
    this->orders_helper = status;
}

ostream& operator << (ostream& out, Orders& orders){
    if(orders.orders_helper){
        out << "----------------------------------------------" << endl << endl
            << "Phone number: " << orders.phone_number
            << "Name: " << orders.name << endl
            << orders.name_of_place << endl
            << orders.comment << endl;
        for(unsigned int i = 0; i < orders.menuPizzas_ordered.size(); i++){
            orders.menuPizzas_ordered[i].set_helper(true);
            out << orders.menuPizzas_ordered[i] << endl;
        }
        for(unsigned int i = 0; i < orders.otherPizzas_ordered.size(); i++){
            orders.otherPizzas_ordered[i].set_helper(true);
            out << orders.otherPizzas_ordered[i] << endl;
        }
        for(unsigned int i = 0; i < orders.sides_ordered.size(); i++){
            orders.otherPizzas_ordered[i].set_helper(true);
            out << orders.sides_ordered[i] << endl;
        }
        out << '\t' << '\t' << "Total: " << orders.total_price << endl << endl
            << "----------------------------------------------" << endl;

    }
    else{
        out << orders.phone_number << "," << orders.name << "," << orders.address << ","
            << orders.comment << " " << orders.baking << " " << orders.ready << " " << orders.paid
            << " " << orders.delivered << " " << orders.home_delivery << " " << orders.orders_helper
            << " " << orders.total_price;

        for(unsigned int i = 0; i < orders.menuPizzas_ordered.size(); i++){
            orders.menuPizzas_ordered[i].set_helper(false);
            out << orders.menuPizzas_ordered[i];
        }
        for(unsigned int i = 0; i < orders.otherPizzas_ordered.size(); i++){
            orders.otherPizzas_ordered[i].set_helper(false);
            out << orders.otherPizzas_ordered[i];
        }
        for(unsigned int i = 0; i < orders.sides_ordered.size(); i++){
            orders.otherPizzas_ordered[i].set_helper(false);
            out << orders.sides_ordered[i];
        }
        out << endl;
    }

    return out;
}

istream& operator >> (istream& in, Orders& orders){
    return in;
}
