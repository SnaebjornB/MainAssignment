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
    address = "Pick-up";
    name[0] = '\0';
    phone_number[0] = '\0';
    total_price = 0;
    pizza_counter = 0;
    menu_pizza_counter = 0;
    sides_counter = 0;
    otherPizzas_ordered.clear();
    menuPizzas_ordered.clear();
    sides_ordered.clear();
}

Orders::Orders(string phone_number, string name, string address) {
    this->phone_number = phone_number;
    this->name = name;
    this->address = address;
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
    total_price = 0;

    for (unsigned int i = 0; i < otherPizzas_ordered.size(); i++){
        total_price += otherPizzas_ordered[i].set_total_price();
    }
    for (unsigned int i = 0; i < menuPizzas_ordered.size(); i++){
        total_price += menuPizzas_ordered[i].get_price();
    }
    for (unsigned int i = 0; i < sides_ordered.size(); i++){
        total_price += sides_ordered[i].get_price();
    }
    return this->total_price;
}

void Orders::set_total_price(){
    total_price = 0;

    for (unsigned int i = 0; i < otherPizzas_ordered.size(); i++){
        total_price += otherPizzas_ordered[i].set_total_price();
    }
    for (unsigned int i = 0; i < menuPizzas_ordered.size(); i++){
        total_price += menuPizzas_ordered[i].get_price();
    }
    for (unsigned int i = 0; i < sides_ordered.size(); i++){
        total_price += sides_ordered[i].get_price();
    }
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

void Orders::add_to_pizza_counter(){
    this->pizza_counter++;
}

void Orders::add_to_menu_pizza_counter(){
    this->menu_pizza_counter++;
}

void Orders::add_to_sides_counter(){
    this->sides_counter++;
}

void Orders::set_in_helper(bool status){
    this->in_helper = status;
}

Orders Orders::operator = (Orders& right_side){
    return right_side;
}

ostream& operator << (ostream& out, Orders& orders){
    if(orders.orders_helper){
        out << "-------------------------------------------" << endl << endl
            << "Phone number: " << orders.phone_number
            << "Name: " << orders.name << endl
            << orders.name_of_place << endl
            << orders.comment << endl;
        for(unsigned int i = 0; i < orders.menuPizzas_ordered.size(); i++){
            orders.menuPizzas_ordered[i].set_helper(true);
            out << orders.menuPizzas_ordered[i] << endl << endl;
        }
        for(unsigned int i = 0; i < orders.otherPizzas_ordered.size(); i++){
            orders.otherPizzas_ordered[i].set_helper(true);
            out << orders.otherPizzas_ordered[i] << endl << endl;
        }
        for(unsigned int i = 0; i < orders.sides_ordered.size(); i++){
            orders.sides_ordered[i].set_helper(true);
            out << orders.sides_ordered[i] << endl << endl;
        }
        out << '\t' << '\t' << '\t';
         if(orders.get_paid_status()){
            out << "Paid" << endl << endl;
         }
         else{
            out << "Total: " << orders.total_price << endl << endl;
         }
            out << "----------------------------------------------" << endl;

    }
    else{
        out << orders.pizza_counter << " " << orders.menu_pizza_counter << " " << orders.sides_counter
            << " " << orders.phone_number << "," << orders.name << "," << orders.address << ","
            << orders.comment << ", " << orders.baking << " " << orders.ready << " " << orders.paid
            << " " << orders.delivered << " " << orders.home_delivery << " " << orders.orders_helper
            << " " << orders.total_price << " ";

        for(unsigned int i = 0; i < orders.menuPizzas_ordered.size(); i++){
            orders.menuPizzas_ordered[i].set_helper(false);
            out << orders.menuPizzas_ordered[i];
        }
        for(unsigned int i = 0; i < orders.otherPizzas_ordered.size(); i++){
            orders.otherPizzas_ordered[i].set_helper(false);
            out << orders.otherPizzas_ordered[i];
        }
        for(unsigned int i = 0; i < orders.sides_ordered.size(); i++){
            orders.sides_ordered[i].set_helper(false);
            out << orders.sides_ordered[i];
        }
        out << endl;
    }

    return out;
}

istream& operator >> (istream& in, Orders& orders){
    if(orders.in_helper){
           in.ignore();
           getline(in,orders.phone_number, ',');  getline(in,orders.name, ','); getline(in,orders.address, ',');
           getline(in,orders.comment, ',') >> orders.baking >> orders.ready >> orders.paid >> orders.delivered
           >> orders.home_delivery >> orders.orders_helper >> orders.total_price;
           orders.menuPizzas_ordered.clear();
           orders.otherPizzas_ordered.clear();
           orders.sides_ordered.clear();
           for(int i = 0; i < orders.menu_pizza_counter; i++){
                //in.ignore();
                in >> orders.menu_pizza;
                orders.menuPizzas_ordered.push_back(orders.menu_pizza);
            }
            for(int i = 0; i < orders.pizza_counter; i++){
                orders.pizza.set_size_helper(true);
                in >> orders.pizza;
                orders.otherPizzas_ordered.push_back(orders.pizza);
            }
            for(int i = 0; i < orders.sides_counter; i++){
                in >> orders.sides;
                orders.sides_ordered.push_back(orders.sides);
            }
        //in.ignore();
    }
    else{
        in >> orders.pizza_counter >> orders.menu_pizza_counter >> orders.sides_counter;
    }
    return in;
}
