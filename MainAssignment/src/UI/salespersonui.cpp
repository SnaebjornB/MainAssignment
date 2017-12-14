#include "salespersonui.h"

SalespersonUI::SalespersonUI() {
    //ctor
}

void SalespersonUI::main_menu(){
    cout << "What do you want to do?" << endl
         << "-----------------------" << endl
         << "1. Take down a new order" << endl
         << "2. Change/add to existing order" << endl
         << "3. View pizza menu" << endl << endl
         << "Please insert the corresponding number: ";
    cin >> input;
    main_input_checker(input);
}

void SalespersonUI::main_input_checker(char input){
    if(input == '1'){
        order_prompt();
    }
    else if(input == '2'){
        change_order_menu();
    }
    else if(input == '3'){
        cout << "3. View pizza menu" << endl;                                   ///vantar
    }

    else{
        cout << endl << "Invalid input! Please choose again." << endl;
        main_menu();
    }
}

void SalespersonUI::order_prompt(){
    string phone_number, name, address;
    char delivery;

    cout << "Phone number: ";
    cin >> phone_number;

    cout << "Name: ";
    cin >> name;

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
                                         /// Vantar að útfæra location breytu og gera address = location eða svo..
    }
    orders.set_phone_number(phone_number);
    orders.set_name(name);
    orders.set_address(address);

    make_new_order_menu();

}

void SalespersonUI::make_new_order_menu() {
    cout << "What would you like to add to the order?" << endl
         << "----------------------------------------" << endl
         << "1. Add a Pizza from the menu" << endl
         << "2. Create a new pizza" << endl
         << "3. Add Sides or Soda" << endl
         << "4. Show price of order" << endl
         << "5. Check order as paid" << endl
         << "5. Finish order" << endl
         << "Enter b to go back" << endl << endl
         << "Input: ";
    cin >> input;
    make_new_order_input_checker(input);
}

void SalespersonUI::make_new_order_input_checker(char input) {
    if(input == '1') {
        string type = "pizza_menu";
        Vectors vectors;
        int choice;
        cout << "Choose the pizza you want to add to the order:" << endl;
        print_pizza_menu(vectors, type);
        cin >> choice;
        vectors.pizza_menu_list[choice - 1].set_print_helper(false);
        vectors.pizza_menu_list[choice - 1].set_helper(false);
        orders.menuPizzas_ordered.push_back(vectors.pizza_menu_list[choice - 1]);
        orders.add_to_menu_pizza_counter();
        make_new_order_menu();
    }
    else if (input == '2') {
        add_pizzasize_menu();
    }
    else if (input == '3') {
        string type = "sides";
        Vectors vectors;
        int choice;
        cout << "Choose sides: " << endl;
        print_sides(vectors, type);
        cin >> choice;
        vectors.sides_list[choice - 1].set_helper(false);
        vectors.sides_list[choice - 1].set_write_helper(false);
        orders.sides_ordered.push_back(vectors.sides_list[choice - 1]);
        cout << orders.sides_ordered[0];
        orders.add_to_sides_counter();
        make_new_order_menu();
    }
    else if(input == '4'){
        cout << "The total for this order is: " << orders.get_total_price() << endl;
        make_new_order_menu();
    }
    else if (input == '5') {
        salesperson_service.write_order(orders);
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
        cout << "1." << endl;
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
        string type = "topping";
        int choice;
        salesperson_service.get_base_price(pizza);
        pizza.margaritaprice(input);
        cout << "Select toppings (0 to stop): ";
        print_toppings(vectors, type);
        while (true){
            cin >> choice;
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
        add_to_excisting_order_menu();
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

Vectors SalespersonUI::print_toppings(Vectors& vectors, string type){
    salesperson_service.read_types(vectors, type);
    for(unsigned int i = 0; i < vectors.topping_list.size(); i++){
        cout << (i+1) << ". " << vectors.topping_list[i] << endl;
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
