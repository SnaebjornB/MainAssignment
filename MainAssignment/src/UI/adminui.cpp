#include "adminui.h"

AdminUI::AdminUI()
{
    //ctor
}

void AdminUI::main_menu(){
    cout << "What do you want to do? " << endl
         << "------------------------" << endl
         << "1. Add/edit toppings" << endl
         << "2. Add/edit sides" << endl
         << "3. Add/edit pizzas" << endl
         << "4. Add/edit locations" << endl
         << "5. Add/edit the pizza menu" << endl << endl
         << "Please input the corresponding number: ";
    cin >> input;
    main_input_checker(input);
}

void AdminUI::main_input_checker(char input){
    if(input == '1'){
        topping_menu();
    }
    else if(input == '2'){
        sides_menu();
    }
    else if(input == '3'){
        pizza_menu();
    }
    else if(input == '4'){
        location_menu();
    }
    else if(input == '5'){
        pizzamenu_menu();
    }
    else{
        cout << "Invalid input! Please choose again." << endl;
        main_menu();
    }
}

void AdminUI::topping_menu(){
    cout << "------------------------" << endl
         << "1. Add topping" << endl
         << "2. Edit current toppings" << endl
         << "3. Remove a topping" << endl
         << "Enter Q to go back" << endl << endl
         << "Input: ";
         cin >> input;
         topping_input_checker(input);
}

void AdminUI::topping_input_checker(char input){
    if(input == '1'){
        add_topping();
    }
    else if(input == '2'){
        cout << "2" << endl;
    }
    else if(input == '3'){
        cout << "3" << endl;
    }
    else if(input == 'q' || input == 'Q'){
        main_menu();
    }
    else{
        cout << "Invalid input! Please choose again." << endl;
        topping_menu();
    }
}

void AdminUI::sides_menu(){
    cout << "------------------------" << endl
         << "1. Add a side-dish" << endl
         << "2. Edit current sides" << endl
         << "3. Remove a side" << endl
         << "Enter Q to go back" << endl << endl
         << "Input: ";
         cin >> input;
         sides_input_checker(input);
}

void AdminUI::sides_input_checker(char input){
    if(input == '1'){
        cout << "1" << endl;
    }
    else if(input == '2'){
        cout << "2" << endl;
    }
    else if(input == '3'){
        cout << "3" << endl;
    }
    else if(input == 'q' || input == 'Q'){
        main_menu();
    }
    else{
        cout << "Invalid input! Please choose again." << endl;
        sides_menu();
    }
}

void AdminUI::pizza_menu(){
    cout << "------------------------" << endl
         << "1. Change allowed sizes" << endl
         << "Enter Q to go back" << endl << endl
         << "Input: ";
         cin >> input;
         pizza_input_checker(input);
}

void AdminUI::pizza_input_checker(char input){
    if(input == '1'){
        cout << "1" << endl;
    }
    else if(input == 'q' || input == 'Q'){
        main_menu();
    }
    else{
        cout << "Invalid input! Please choose again." << endl;
        pizza_menu();
    }
}

void AdminUI::location_menu(){
    cout << "------------------------" << endl
         << "1. Add a location" << endl
         << "2. Close a location" << endl
         << "Enter Q to go back" << endl << endl
         << "Input: ";
         cin >> input;
         sides_input_checker(input);
}

void AdminUI::location_input_checker(char input){
    if(input == '1'){
        cout << "1" << endl;
    }
    else if(input == '2'){
        cout << "2" << endl;
    }
    else if(input == 'q' || input == 'Q'){
        main_menu();
    }
    else{
        cout << "Invalid input! Please choose again." << endl;
        location_menu();
    }
}

void AdminUI::pizzamenu_menu(){
    cout << "------------------------" << endl
         << "1. Add a pizza recipe" << endl
         << "2. Edit a pizza" << endl
         << "3. Remove a pizza recipe" << endl
         << "Enter Q to go back" << endl << endl
         << "Input: ";
         cin >> input;
         pizzamenu_input_checker(input);
}

void AdminUI::pizzamenu_input_checker(char input){
    if(input == '1'){
        cout << "1" << endl;
    }
    else if(input == '2'){
        cout << "2" << endl;
    }
    else if(input == '3'){
        cout << "3" << endl;
    }
    else if(input == 'q' || input == 'Q'){
        main_menu();
    }
    else{
        cout << "Invalid input! Please choose again." << endl;
        location_menu();
    }
}
///Breyta svo löglegt add_topping
void AdminUI::add_topping(){
    string name;
    char type;
    int price;

    cin >> name >> price >> type;
    Topping topping(name, price, type);

    admin_repo.write_topping(topping);

}
