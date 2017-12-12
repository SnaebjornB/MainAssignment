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
         << "3. Add locations" << endl
         << "4. Add/edit the pizza menu" << endl << endl
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
        location_menu();
    }
    else if(input == '4'){
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
         << "4. Change price of topping category" << endl
         << "Enter b to go back" << endl << endl
         << "Input: ";
         cin >> input;
         topping_input_checker(input);
}

void AdminUI::topping_input_checker(char input){
    if(input == '1'){
        Topping topping = create_topping();
        admin_service.add_topping(topping);
        cout << "You added " << topping
             << " to the list of toppings." << endl;
        topping_menu();
    }
    else if(input == '2'){
        string type = "topping";
        print_toppings();

        cout << "Choose the topping you want to change: ";
        int choice;
        cin >> choice;
        cout << endl << "You selected:" << vectors.topping_list[choice-1] << endl
             << "Recreate this topping:" << endl;
        vectors.topping_list[choice-1] = create_topping();
        admin_service.write_type(vectors, type);
        topping_menu();
    }
    else if(input == '3'){
        string type = "topping";
        print_toppings();

        cout << "Choose the topping you want to remove: ";
        unsigned int num_of_line;
        cin >> num_of_line;

        admin_service.erase_type(vectors, num_of_line, type);
        topping_menu();
    }
    else if(input == '4'){
        int price;
        string type = "topping";
        admin_service.read_types(vectors, type);
        cout << "Insert the letter that represents the category you want to assign a new price to: ";
        cin >> input;
        cout << "What is the new price? ";
        cin >> price;

        for (unsigned int i = 0; i < vectors.topping_list.size(); i++){
            if(input == vectors.topping_list[i].get_type()){
                vectors.topping_list[i].set_price(price);
            }
        }
        admin_service.write_type(vectors, type);

        cout << "Price of topping category " << input << " is now " << price << endl;
        topping_menu();

    }
    else if(input == 'b' || input == 'B'){
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
         << "Enter b to go back" << endl << endl
         << "Input: ";
         cin >> input;
         sides_input_checker(input);
}

void AdminUI::sides_input_checker(char input){
    if(input == '1'){
        Sides sides = create_sides();
        admin_service.add_sides(sides);
        sides.set_helper(true);
        cout << "You added " << sides << " to the list of side dishes." << endl;
        sides_menu();
    }
    else if(input == '2'){
        string type = "sides";
        print_sides();

        cout << "Choose the side-dish you want to change: ";
        int choice;
        cin >> choice;
        cout << endl << "You selected:" << vectors.sides_list[choice-1] << endl
             << "Recreate this side-dish:" << endl;
        vectors.sides_list[choice-1] = create_sides();
        admin_service.write_type(vectors, type);
        sides_menu();
    }
    else if(input == '3'){
        cout << "3" << endl;
    }
    else if(input == 'b' || input == 'B'){
        main_menu();
    }
    else{
        cout << "Invalid input! Please choose again." << endl;
        sides_menu();
    }
}

void AdminUI::location_menu(){
    cout << "------------------------" << endl
         << "1. Add a location" << endl
         << "2. Close a location" << endl
         << "Enter b to go back" << endl << endl
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
    else if(input == 'b' || input == 'B'){
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
         << "Enter b to go back" << endl << endl
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
    else if(input == 'b' || input == 'B'){
        main_menu();
    }
    else{
        cout << "Invalid input! Please choose again." << endl;
        location_menu();
    }
}


///Create föll: topping, o.s.frv.
Topping AdminUI::create_topping(){
    string name;
    char type;
    int price, size;

    cout << "Name: ";
    cin.ignore();
    getline (cin, name);

    cout << "Size: ";
    cin >> size;

    cout << "Price: ";
    cin >> price;

    cout << "Type: ";
    cin >> type;

    return Topping(name, price, type, size);
}

void AdminUI::print_toppings(){
    string type = "topping";
    admin_service.read_types(vectors, type);
    for(unsigned int i = 0; i < vectors.topping_list.size(); i++){
        cout << (i+1) << ". " << vectors.topping_list[i] << " ";
    }
}

Sides AdminUI::create_sides(){
    string name;
    int price;

    cout << "Name: ";
    cin.ignore();
    getline (cin, name);

    cout << "Price: ";
    cin >> price;

    return Sides(name, price);
}

void AdminUI::print_sides(){
    string type = "sides";
    cout << "1";
    admin_service.read_types(vectors, type);
    for(unsigned int i = 0; i < vectors.sides_list.size(); i++){
        cout << (i+1) << ". " << vectors.sides_list[i] << " ";
    }
}
