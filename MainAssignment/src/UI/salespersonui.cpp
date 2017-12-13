#include "salespersonui.h"

SalespersonUI::SalespersonUI() {
    //ctor
}

void SalespersonUI::main_menu(){
    cout << "What do you want to do?" << endl
         << "-----------------------" << endl
         << "1. Take down new order" << endl
         << "2. Change/add to excisting order" << endl
         << "3. show price of order" << endl
         << "4. Check order to paid" << endl << endl
         << "Please insert the corresponding number: ";
    cin >> input;
    main_input_checker(input);
}

void SalespersonUI::main_input_checker(char input){
    if(input == '1'){
        make_new_order_menu();
    }
    else if(input == '2'){
        change_order_menu();
    }
    else if(input == '3'){
        cout << "3. show price of order" << endl;                               ///vantar
    }
    else if(input == '4'){
        cout << "4. Check order to paid" << endl;                               ///vantar
    }
    else{
        cout << endl << "Invalid input! Please choose again." << endl;
        main_menu();
    }
}

void SalespersonUI::make_new_order_menu() {
    cout << "What would you like to add to the order?" << endl
         << "----------------------------------------" << endl
         << "1. Add Pizza" << endl
         << "2. Add Sides or Soda" << endl
         << "Enter b to go back" << endl << endl
         << "Input: ";
    cin >> input;
    make_new_order_input_checker(input);
}

void SalespersonUI::make_new_order_input_checker(char input) {
    if(input == '1') {
        add_pizza_menu();
    }
    else if (input == '2') {
        cout << "2. Add Sides or Soda" << endl;                                 ///vantar
    }
    else if (input == 'b' || input == 'B') {
        main_menu();
    }
    else{
        cout << endl << "Invalid input! Please choose again." << endl;
        make_new_order_menu();
    }
}

void SalespersonUI::change_order_menu() {
    cout << "What whould you like to do?" << endl
         << "-----------------------" << endl
         << "1. Add to excisting order" << endl
         << "2. Remove sides" << endl
         << "3. Remove pizza" << endl
         << "Enter b to go back" << endl << endl
         << "Please insert the corresponding number: ";
    cin >> input;    
    change_order_input_checker(input);
}

void SalespersonUI::change_order_input_checker(char input) {
    if(input == '1'){
        add_to_excisting_order_menu();
    }
    else if(input == '2'){
        cout << "2. Remove sides" << endl;                                      ///vantar
    }
    else if(input == '3'){
        cout << "3. Remove pizza" << endl;                                      ///vantar
    }
    else if (input == 'b' || input == 'B') {
        main_menu();
    }
    else{
        cout << endl << "Invalid input! Please choose again." << endl;
        change_order_menu();
    }
}

void SalespersonUI::add_pizza_menu() {
    cout << "Whould you like to order a pizza from the menu or make your own?" << endl
         << "---------------------------------------------------------------------" << endl
         << "1. Add a pizza from menu" << endl
         << "2. Make your own pizza" << endl
         << "Enter b to go back" << endl << endl
         << "Input: ";
    cin >> input;
    add_pizza_input_checkout(input);
}

void SalespersonUI::add_pizza_input_checkout(char input) {
    if(input == '1') {
        cout << "1. Add a pizza from menu" << endl;                             ///vantar
    }
    else if (input == '2') {
        add_pizzasize_menu();                             
    }
    else if (input == 'b' || input == 'B') {
        make_new_order_menu();
    }
    else{
        cout << endl << "Invalid input! Please choose again." << endl;
        add_pizza_menu(); 
    }
}

void SalespersonUI::add_to_excisting_order_menu() {
    cout << "What would you like to add to the order?" << endl
    << "----------------------------------------" << endl
    << "1. Add Pizza" << endl
    << "2. Add Sides or Soda" << endl
    << "Enter b to go back" << endl << endl
    << "Input: ";
    cin >> input;
    add_to_excisting_order_input_checkout(input);
}

void SalespersonUI::add_to_excisting_order_input_checkout(char input) {
    if(input == '1') {
        add_pizza_menu();
    }
    else if (input == '2') {
        cout << "2. Add Sides or Soda" << endl;                                 ///vantar
    }
    else if (input == 'b' || input == 'B') {
        change_order_menu();
    }
    else{
        cout << endl << "Invalid input! Please choose again." << endl;
        add_to_excisting_order_menu();
    }
}

void SalespersonUI::add_pizzasize_menu() {
    cout << "What size of pizza do you want?" << endl
         << "-------------------------------" << endl
         << "1. 9\"  " << endl
         << "2. 12\" " << endl
         << "3. 16\" " << endl
         << "Enter b to go back" << endl << endl
         << "Input: ";
    cin >> input;
    add_pizzasize_input_checkout(input);
}

void SalespersonUI::add_pizzasize_input_checkout(char input) {
    if(input == '1' || input == '2' || input == '3') {
        pizza.margaritaprice(input);
    }
    else if (input == 'b' || input == 'B') {
        add_pizza_menu();
    }
    else{
        cout << endl << "Invalid input! Please choose again." << endl;
        add_pizzasize_menu();
    }
}
