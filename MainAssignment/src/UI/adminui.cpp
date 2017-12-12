#include "adminui.h"

AdminUI::AdminUI()
{
    //ctor
}

void AdminUI::main_menu(){
    cout << string(50, '\n');
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
    cout << string(50, '\n');
    cout << "------------------------" << endl
         << "1. Add topping" << endl
         << "2. Edit current toppings" << endl
         << "3. Remove a topping" << endl
         << "4. Change price of topping category" << endl
         << "Enter Q to go back" << endl << endl
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

        ///admin_repo.write_topping(topping);
        /*
        Employee employee = create_employee();
        employee_service.add_employee(employee);
        */
    }
    else if(input == '2'){
        int choice;
        admin_service.print_toppings(vectors);
        cout << "1" << endl; ///debugger
        for(unsigned int i = 0; i < vectors.topping_list.size(); i++){
            cout << (i+1) << ". " << vectors.topping_list[i] << " ";
        }
        cout << "Choose the topping you want to change: ";
        cin >> choice;
        cout << endl << "You selected:" << vectors.topping_list[choice-1] << endl
             << "Recreate this topping:" << endl;
        vectors.topping_list[choice-1] = create_topping();
        admin_service.write_toppings(vectors);
        topping_menu();
    }
    else if(input == '3'){
        cout << "3" << endl;
    }
    else if(input == '4'){
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
    cout << string(50, '\n');
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
    cout << string(50, '\n');
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
    cout << string(50, '\n');
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
    cout << string(50, '\n');
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
