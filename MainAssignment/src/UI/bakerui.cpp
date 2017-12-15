#include "bakerui.h"
#include "mainui.h"

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::location() {
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

void BakerUI::main_menu(){

    cout << "What do you want to do?" << endl
         << "-----------------------" << endl
         << "1. Get list of orders to be made" << endl
         << "2. Show next order to make" << endl
         << "3. Check order as in making" << endl
         << "4. Check order as ready" << endl
         << "Input q to logout" << endl << endl
         << "Please insert the corresponding number: ";
    cin >> input;
    main_input_checker(input);
}

void BakerUI::main_input_checker(char input){
    if(input == '1'){

        string status = "ordered";
        print_orders(vectors, status);
        vectors.orders_list.clear();
        main_menu();
    }
    else if(input == '2'){
        string status = "ordered";
        print_next_order(vectors, status);
        main_menu();
    }
    else if(input == '3'){
        cout << "3. Check order as in making" << endl;

        string current_status = "ordered";
        string next_status = "making";
        change_status_making(current_status, next_status);

    }
    else if(input == '4'){
        cout << "4. Check order ready" << endl;

        string current_status = "making";
        string next_status = "ready";
        change_status_ready(current_status, next_status);
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

void BakerUI::print_locations(){
    ///lesa loactions.txt inn í vector
    baker_service.read_locations(vectors);

    ///Prenta út vector
    for(unsigned int i = 0; i < vectors.locations_list.size(); i++){
        cout << (i+1) << ". " << vectors.locations_list[i] << endl;
    }
}

Vectors BakerUI::print_orders(Vectors& vectors, string status){
    ///Lesa active orders inn á vector
    baker_service.read_orders(vectors, status, location_name);

    for(unsigned int i = 0; i < vectors.orders_list.size(); i++){
        cout << (i+1) << ". " << vectors.orders_list[i] << endl;
    }
    return vectors;
}

void BakerUI::print_next_order(Vectors& vectors, string status){
    baker_service.read_orders(vectors, status, location_name);
    if(vectors.orders_list.size() > 0){
        cout << vectors.orders_list[0] << endl;
    }
}

void BakerUI::check_in_making(int choice, Vectors& vectors){
    vectors.orders_list[choice-1].set_baking_status(true);
}

void BakerUI::change_status_ready(string current_status, string next_status){
    print_orders(vectors, current_status);
        unsigned int choice = 0;
    do {
        cout << "Choose the order you want to mark as ready: ";
        cin >> choice;

        if (choice > vectors.orders_list.size() || choice < 1) {
            cout << "Invalid input, try again" << endl;
        }
    }
    while (choice > vectors.orders_list.size() || choice < 1);

    vectors.orders_list[choice - 1].set_baking_status(true);
    baker_service.check_in_making(vectors, location_name, current_status, next_status);

    main_menu();
}

void BakerUI::change_status_making(string current_status, string next_status){
    print_orders(vectors, current_status);
        unsigned int choice = 0;
    do {
        cout << "Choose the order you want to mark as in the oven";
        cin >> choice;

        if (choice > vectors.orders_list.size() || choice < 1) {
            cout << "Invalid input, try again" << endl;
        }
    }
    while (choice > vectors.orders_list.size() || choice < 1);

    vectors.orders_list[choice - 1].set_baking_status(true);
    baker_service.check_in_making(vectors, location_name, current_status, next_status);

    main_menu();
}
