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
         << "2. Print all toppings" << endl
         << "3. Edit current toppings" << endl
         << "4. Remove a topping" << endl
         << "5. Change price of topping category" << endl
         << "Enter B to go back or Q to quit." << endl << endl
         << "Input: ";
         cin >> input;
         topping_input_checker(input);
}

void AdminUI::topping_input_checker(char input){
    if(input == '1'){
        Topping topping = create_topping();
        try {
            admin_service.add_topping(topping);
            admin_service.add_topping(topping);
            cout << "You added " << topping
            << " to the list of toppings." << endl;
        }
        catch(InvalidNameException e) {
            cout << e.getMessage() << endl;
        }
        catch(InvalidInchesException e) {
            cout << e.getMessage() << endl;
        }
        catch(InvalidTypeException e) {
            cout << e.getMessage() << endl;
        }


        topping_menu();
    }
    if(input == '2') {
        print_toppings();
        topping_menu();
    }
    else if(input == '3'){                      //ATH
        print_toppings();

        string type = "topping";
        int choice;
        int sizeofVector = (int)vectors.topping_list.size();
        do {
            cout << "Choose the topping you want to change: ";
            cin >> choice;
            if (choice <= 0 || choice > sizeofVector) {
                cout << "Invalid input! Please choose again." << endl;
            }
        } while ( choice <= 0 || choice > sizeofVector);

        cout << endl << "You selected:" << vectors.topping_list[choice-1] << endl
        << "Recreate this topping:" << endl;

        Topping topping = create_topping();
        try {
            admin_service.add_topping(topping);
        }
        catch(InvalidNameException e) {
            cout << e.getMessage() << endl;
        }
        catch(InvalidInchesException e) {
            cout << e.getMessage() << endl;
        }
        catch(InvalidTypeException e) {
            cout << e.getMessage() << endl;
        }

        vectors.topping_list[choice-1] = topping;
        admin_service.write_type(vectors, type);
        topping_menu();
    }
    else if(input == '4'){
        print_toppings();
        string type = "topping";

        int num_of_line;
        int sizeofVector = (int) vectors.topping_list.size();

        do {
            cout << "Choose the topping you want to change: ";
            cin >> num_of_line;
            if (num_of_line <= 0 || num_of_line > sizeofVector) {
                cout << "Invalid input! Please choose again." << endl;
            }
        } while ( num_of_line <= 0 || num_of_line > sizeofVector);

        admin_service.erase_type(vectors, num_of_line, type);
        topping_menu();
    }
    else if(input == '5'){
        int price;
        int pizza_size = 0;
        string type = "topping";
        admin_service.read_types(vectors, type);
        cout << "Insert the letter that represents the category you want to assign a new price to: ";
        cin >> input;
        cout << "what size of pizza?";
        cin >> pizza_size;
        cout << "What is the new price? ";
        cin >> price;

        for (unsigned int i = 0; i < vectors.topping_list.size(); i++){
            if(input == vectors.topping_list[i].get_type() && pizza_size == vectors.topping_list[i].get_size()){
                
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
    else if(input == 'q' || input == 'Q'){
        cout << endl <<"Thank you and have a nice day." << endl << endl;
    }
    else{
        cout << "Invalid input! Please choose again." << endl;
        topping_menu();
    }
}
                                                                        //ready
void AdminUI::sides_menu(){
    cout << "------------------------" << endl
         << "1. Add a side-dish" << endl
         << "2. Print all sides" << endl
         << "3. Edit current sides" << endl
         << "4. Remove a side" << endl
         << "Enter B to go back or Q to quit." << endl << endl
         << "Input: ";
         cin >> input;
         sides_input_checker(input);
}

void AdminUI::sides_input_checker(char input){
    if(input == '1'){
        try {
            admin_service.add_sides(create_sides());
        }
        catch(InvalidNameException e) {
            cout << e.getMessage() << endl;
        }
        Sides sides = create_sides();
        admin_service.add_sides(sides);
        sides.set_helper(true);
        cout << "You added " << sides << " to the list of side dishes." << endl;
        sides_menu();
    }
    else if(input == '2') {
        print_sides();
    }
    else if(input == '3'){
        string type = "sides";
        print_sides();
        cout << "Choose the side-dish you want to change: ";
        int choice;
        int sizeofVector = (int)vectors.sides_list.size();

        do{
            cin >> choice;
            if (choice <= 0 || choice > sizeofVector) {
                cout << "Invalid input! Please choose again." << endl;
            }
        } while ( choice <= 0 || choice > sizeofVector);

        cout << endl << "You selected:" << vectors.sides_list[choice-1] << endl
        << "Recreate this side-dish:" << endl;

        try {
            admin_service.add_sides(create_sides());
        }
        catch(InvalidNameException e) {
            cout << e.getMessage() << endl;
        }

        vectors.sides_list[choice-1] = create_sides();
        admin_service.write_type(vectors, type);
        sides_menu();
    }
    else if(input == '4'){
        string type = "sides";
        print_sides();
        int num_of_line;
        int sizeofVector = (int) vectors.sides_list.size();
        do {
        cout << "Choose the side-dish you want to remove: ";
        cin >> num_of_line;
            if (num_of_line <= 0 || num_of_line > sizeofVector) {
                cout << "Invalid input! Please choose again." << endl;
            }
        } while ( num_of_line <= 0 || num_of_line > sizeofVector);

        admin_service.erase_type(vectors, num_of_line, type);
        sides_menu();
    }
    else if(input == 'b' || input == 'B'){
        main_menu();
    }
    else if(input == 'q' || input == 'Q'){
        cout << endl <<"Thank you and have a nice day." << endl << endl;
    }
    else{
        cout << "Invalid input! Please choose again." << endl;
        sides_menu();
    }
}

void AdminUI::location_menu(){
    cout << "------------------------" << endl
         << "1. Add a location" << endl
         << "Enter B to go back or Q to quit." << endl << endl
         << "Input: ";
         cin >> input;
         location_input_checker(input);
}

void AdminUI::location_input_checker(char input){
    if(input == '1'){
        ///Add-a location í skrá með locations
        string location;

        cout << "Location's name: ";
        cin.ignore();
        getline (cin, location);

        admin_service.add_location(location);

        cout << "You added " << location << " to the list of locations." << endl;
        location_menu();

    }
    else if(input == 'b' || input == 'B'){
        main_menu();
    }
    else if(input == 'q' || input == 'Q'){
        cout << endl <<"Thank you and have a nice day." << endl << endl;
    }
    else{
        cout << "Invalid input! Please choose again." << endl;
        location_menu();
    }
}

void AdminUI::pizzamenu_menu(){
    cout << "------------------------" << endl
         << "1. Add a pizza recipe" << endl
         << "2. Print pizza menu" << endl
         << "3. Edit a pizza" << endl
         << "4. Remove a pizza recipe" << endl
         << "5. Change price of pizza size" << endl
         << "6. View the pizza menu" << endl
         << "Enter B to go back or Q to quit." << endl << endl
         << "Input: ";
         cin >> input;
         pizzamenu_input_checker(input);
}

void AdminUI::pizzamenu_input_checker(char input){
    if(input == '1'){
        Menu_Pizza menu_pizza = create_menu_pizza();
        admin_service.add_menu_pizza(menu_pizza);
        menu_pizza.set_helper(true);
        cout << "You added " << menu_pizza << " to the pizza menu." << endl;
        pizzamenu_menu();
    }
    else if(input == '2') {
        print_pizza_menu();
    }
    else if(input == '3'){
        string type = "pizza_menu";
        print_pizza_menu();

        cout << "Choose the pizza you want to change: ";
        int choice;
        cin >> choice;
        cout << endl << "You selected:" << vectors.pizza_menu_list[choice-1] << endl
             << "Recreate this pizza:" << endl;
        vectors.pizza_menu_list[choice-1] = create_menu_pizza();
        admin_service.write_type(vectors, type);
        pizzamenu_menu();
    }
    else if(input == '4'){
        string type = "pizza_menu";
        print_pizza_menu();

        cout << "Choose the pizza you want to remove: ";
        unsigned int num_of_line;
        cin >> num_of_line;

        admin_service.erase_type(vectors, num_of_line, type);
        pizzamenu_menu();
    }
    else if(input == '5') {
        cout << "price of 9\" is: ";
        int inches9 = 0;
        cin >> inches9;
        pizza.set_inches9(inches9);
        cout << "price of 12\" is: ";
        int inches12 = 0;
        cin >> inches12;
        pizza.set_inches12(inches12);
        cout << "price of 16\" is: ";
        int inches16 = 0;
        cin >> inches16;
        pizza.set_inches16(inches16);

        admin_service.add_margarita_price(pizza);
    }
    else if(input == '6') {
        cout << "5. View the pizza menu" << endl;                               //vantar
    }
    else if(input == 'b' || input == 'B'){
        main_menu();
    }
    else if(input == 'q' || input == 'Q'){
        cout << endl <<"Thank you and have a nice day." << endl << endl;
    }
    else{
        cout << "Invalid input! Please choose again." << endl;
        location_menu();
    }
}


///Create & print föll: topping, o.s.frv.
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
        cout << (i+1) << ". " << vectors.topping_list[i];
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
    admin_service.read_types(vectors, type);
    for(unsigned int i = 0; i < vectors.sides_list.size(); i++){
        cout << (i+1) << ". " << vectors.sides_list[i];
    }
}

Menu_Pizza AdminUI::create_menu_pizza(){
    string name;
    int size, price;

    cout << "Name: ";
    cin.ignore();
    getline (cin, name);

    cout << "Size: ";
    cin >> size;

    cout << "Price: ";
    cin >> price;

    Menu_Pizza menu_pizza(name, price, size);

    return menu_pizza;
}

string AdminUI::create_location(){
    string location;

    cout << "Location's name: ";
    cin.ignore();
    getline (cin, location);

    return location;
}

void AdminUI::print_pizza_menu(){
    string type = "pizza_menu";
    admin_service.read_types(vectors, type);
    for(unsigned int i = 0; i < vectors.pizza_menu_list.size(); i++){
        cout << (i+1) << ". " << vectors.pizza_menu_list[i];
    }
}

