#include "salespersonui.h"
#include "mainui.h"

SalespersonUI::SalespersonUI() {
    //ctor
}

void SalespersonUI::location() {
    print_locations();

    int num_of_location;
    int checker = (int)vectors.locations_list.size();
    do{
        cout << "pick your location: ";
        cin >> num_of_location;
        if(num_of_location < 0 || num_of_location > checker){
            cout << "Invalid input! Try again." << endl;
        }
    }while(num_of_location < 0 || num_of_location > checker);
    location_name = vectors.locations_list[num_of_location-1];

    main_menu();
}

void SalespersonUI::main_menu(){
    cout << "What do you want to do?" << endl
         << "-----------------------" << endl
         << "1. Take down a new order" << endl
         << "Input q to logout" << endl << endl
         << "Please insert the corresponding number: ";
    cin >> input;
    main_input_checker(input);
}

void SalespersonUI::main_input_checker(char input){
    if(input == '1'){
        Orders orders = order_prompt();
        try {
            salesperson_service.add_order(orders, location_name);
        }
        catch(InvalidNameException e) {
            cout << e.getMessage() << endl;
            Orders orders = order_prompt();
        }
        catch(InvalidPhonenumberException e) {
            cout << e.getMessage() << endl;
            Orders orders = order_prompt();
        }
        make_new_order_menu();
    }
    else if(input == 'q' || input == 'Q'){
        MainUI mainui;
        mainui.main_menu();
    }
    else{
        cout << endl << "Invalid input! Please choose again." << endl;
        main_menu();
    }
}

Orders SalespersonUI::order_prompt(){
    string phone_number, name, address;
    char delivery;

    cout << "Phone number: ";
    cin >> phone_number;


    cout << "Name: ";
    cin >> ws;
    getline(cin, name);

    do {
        cout << "Home delivery (y if it is, n if it's not) ";
        cin >> delivery;


        if(delivery == 'y' || delivery == 'Y'){
            cout << "Address: ";
            cin >> ws;
            getline(cin, address);
            orders.set_home_delivery_status(true);
        }
        else if(delivery == 'n' || delivery == 'N'){
            orders.set_home_delivery_status(false);
            /// Vantar a� �tf�ra location breytu og gera address = location e�a svo..
        }
        else {
            cout << "wrong input, try again." << endl;
        }
    }
    while (!(delivery == 'y' || delivery == 'Y' ||delivery == 'n' || delivery == 'N'));

    orders.set_phone_number(phone_number);
    orders.set_name(name);
    orders.set_address(address);

    Orders orders(phone_number, name, address);

    return  orders;
}

void SalespersonUI::make_new_order_menu() {
    cout << "What would you like to add to the order?" << endl
         << "----------------------------------------" << endl
         << "1. Add a Pizza from the menu" << endl
         << "2. Create a new pizza" << endl
         << "3. Add Sides or Soda" << endl
         << "4. Show price of order" << endl
         << "5. Check order as paid" << endl
         << "6. Finish order" << endl
         << "Enter b to go back" << endl << endl
         << "Input: ";
    cin >> input;
    make_new_order_input_checker(input);
}

void SalespersonUI::make_new_order_input_checker(char input) {
    if(input == '1') {
        add_menu_pizza();
    }
    else if (input == '2') {
        add_pizzasize_menu();
    }
    else if (input == '3') {
        add_sides();
    }
    else if(input == '4'){
        cout << "The total for this order is: " << orders.get_total_price() << endl;
        make_new_order_menu();
    }
    else if (input == '5') {
        check_order_as_paid();
    }
    else if (input == '6') {
        finish_order();
    }
    else if (input == 'b' || input == 'B') {
        main_menu();
    }
    else{
        cout << endl << "Invalid input! Please choose again." << endl;
        make_new_order_menu();
    }
}

void SalespersonUI::add_to_order_menu() {
    cout << "What would you like to add to the order?" << endl
         << "----------------------------------------" << endl
         << "1. Add a Pizza from the menu" << endl
         << "2. Create a new pizza" << endl
         << "3. Add Sides or Soda" << endl
         << "4. Show price of order" << endl
         << "5. Check order as paid" << endl
         << "6. Finish order" << endl
         << "Enter b to go back" << endl << endl
         << "Input: ";
    cin >> input;
    make_new_order_input_checker(input);
}

void SalespersonUI::add_to_order_input_checker(char input) {
    if(input == '1') {
        add_menu_pizza();
    }
    else if (input == '2') {
        add_pizzasize_menu();
    }
    else if (input == '3') {
        add_sides();
    }
    else if(input == '4'){
        cout << "The total for this order is: " << orders.get_total_price() << endl;
        make_new_order_menu();
    }
    else if (input == '5') {
        check_order_as_paid();
    }
    else if (input == '6') {
        finish_order();
    }
    else if (input == 'b' || input == 'B') {
        main_menu();
    }
    else{
        cout << endl << "Invalid input! Please choose again." << endl;
        make_new_order_menu();
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
        string type = "topping";
        int choice;

        salesperson_service.get_base_price(pizza);
        pizza.margaritaprice(input);

        print_toppings(vectors, type, input);
        int checker = (int)vectors.topping_list.size();

        while (true){
            do{
                cout << "Select toppings (0 to stop): ";
                cin >> choice;
                if(choice < 0 || choice > checker){
                    cout << "Invalid input! Try again." << endl;
                }
            }while(choice < 0 || choice > checker);
                if (choice == 0){
                    break;
                }
            pizza.pizza_toppings.push_back(vectors.topping_list[choice - 1]);
            pizza.add_to_topping_counter();
        }
        pizza.set_write_order_helper(false);
        pizza.set_helper(false);
        pizza.set_size_helper(true);

        orders.otherPizzas_ordered.push_back(pizza);
        orders.add_to_pizza_counter();
        pizza.pizza_toppings.clear();
        make_new_order_menu();
    }
    else if (input == 'b' || input == 'B') {
        make_new_order_menu();
    }
    else{
        cout << endl << "Invalid input! Please choose again." << endl;
        add_pizzasize_menu();
    }
}

Vectors SalespersonUI::print_pizza_menu(Vectors& vectors, string type){
    salesperson_service.read_types(vectors, type);
    for(unsigned int i = 0; i < vectors.pizza_menu_list.size(); i++){
        cout << (i+1) << ". " << vectors.pizza_menu_list[i] << endl;
    }

    return vectors;
}

Vectors SalespersonUI::print_toppings(Vectors& vectors, string type, char input){
    salesperson_service.read_types(vectors, type);
    for(unsigned int i = 0; i < vectors.topping_list.size(); i++){
        vectors.topping_list[i].set_helper(true);
        if(input == '1'){
            if(vectors.topping_list[i].get_size() == 9){
                cout << (i+1) << ". " << vectors.topping_list[i] << endl;
            }
        }
        if(input == '2'){
            if(vectors.topping_list[i].get_size() == 12){
                cout << (i+1) << ". " << vectors.topping_list[i] << endl;
            }
        }
        if(input == '3'){
            if(vectors.topping_list[i].get_size() == 16){
                cout << (i+1) << ". " << vectors.topping_list[i] << endl;
            }
        }
    }
    return vectors;
}

Vectors SalespersonUI::print_sides(Vectors& vectors, string type){
    salesperson_service.read_types(vectors, type);
    for(unsigned int i = 0; i < vectors.sides_list.size(); i++){
        cout << (i+1) << ". " << vectors.sides_list[i] << endl;
    }

    return vectors;
}

void SalespersonUI::print_locations(){
    ///lesa loactions.txt inn � vector
    salesperson_service.read_locations(vectors);

    ///Prenta �t vector
    for(unsigned int i = 0; i < vectors.locations_list.size(); i++){
        cout << (i+1) << ". " << vectors.locations_list[i] << endl;
    }
}

void SalespersonUI::add_to_order(){
    string ordered = "ordered", making = "making", ready = "ready";
    int choice = 0;

    salesperson_service.read_orders(vectors, ordered, location_name);

    for(unsigned int i = 0; i < vectors.orders_list.size(); i++){
        cout << (i+1) << ". " << vectors.orders_list[i].get_name()
             << " " << vectors.orders_list[i].get_phone_number() << endl;
    }
    cout << "Which order do you need to add to? ";
    cin >> choice;

    cout << vectors.orders_list[choice - 1] << endl;

    current_order.push_back(vectors.orders_list[choice - 1]);

    add_to_order_menu();
    vectors.orders_list.clear();

    main_menu();
}

void SalespersonUI::add_menu_pizza(){
    string type = "pizza_menu";
    Vectors vectors;
    int choice;
    print_pizza_menu(vectors, type);
    int checker = (int) vectors.pizza_menu_list.size();

    do{
        cout << "Choose the pizza you want to add to the order: ";
        cin >> choice;
        if(choice < 1 || choice > checker){
            cout << "Invalid input! Try again" << endl;
        }
    }while(choice < 1 || choice > checker);

    vectors.pizza_menu_list[choice - 1].set_print_helper(false);
    vectors.pizza_menu_list[choice - 1].set_helper(false);

    orders.menuPizzas_ordered.push_back(vectors.pizza_menu_list[choice - 1]);
    orders.add_to_menu_pizza_counter();

    make_new_order_menu();
}

void SalespersonUI::add_sides(){
    string type = "sides";
    Vectors vectors;
    int choice;

    print_sides(vectors, type);
    int checker = (int) vectors.sides_list.size();

    do{
        cout << "Choose sides: " << endl;
        cin >> choice;
        if(choice < 1 || choice > checker){
            cout << "Invalid input! Try again." << endl;
        }
    }while(choice < 1 || choice > checker);

    vectors.sides_list[choice - 1].set_helper(false);
    vectors.sides_list[choice - 1].set_write_helper(false);
    orders.sides_ordered.push_back(vectors.sides_list[choice - 1]);

    cout << orders.sides_ordered[0];
    orders.add_to_sides_counter();

    make_new_order_menu();
}

void SalespersonUI::check_order_as_paid(){
    char choice;
    while(true){
        cout << "Has the order been paid? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y'){
            orders.set_paid_status(true);
            cout << "Order was marked as paid" << endl;
            make_new_order_menu();
        }
        else if(choice == 'n' || choice == 'N'){
            cout << "Order was not marked as paid" << endl;
            make_new_order_menu();
        }
        else{
            cout << "Invalid input!" << endl;
        }
    }
}

void SalespersonUI::finish_order(){
    string comment;

    cout << "Comment: ";
    cin >> comment;

    orders.set_comment(comment);
    orders.set_total_price();
    cout << orders;
    salesperson_service.write_order(orders, location_name);

    main_menu();
}
