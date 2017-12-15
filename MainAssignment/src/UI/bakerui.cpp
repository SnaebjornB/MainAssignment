#include "bakerui.h"

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::location() {
    print_locations();
    cout << "pick your location: ";
    unsigned int num_of_location;
    cin >> num_of_location;
    ///Velja nafn númer num_of_location
    location_name = vectors.locations_list[num_of_location-1];

    main_menu();
}

void BakerUI::main_menu(){

    cout << "What do you want to do?" << endl
         << "-----------------------" << endl
         << "1. Get list of all orders" << endl
         << "2. Show next order to make" << endl
         << "3. Check order as in making" << endl
         << "4. Check order as ready" << endl
         << "Please insert the corresponding number: ";
    cin >> input;
    main_input_checker(input);
}

void BakerUI::main_input_checker(char input){
    if(input == '1'){
        cout << "1. Get list of all orders" << endl;
        ///Prenta út ActiveOrdersLocation_Name.txt
        string status = "ordered";
        print_orders(vectors, status);
        ///Prenta út MakingOrdersLocation_name
        status = "making";
        print_orders(vectors, status);
        main_menu();

    }
    else if(input == '2'){
        string status = "active";
        print_next_order(vectors, status);
        main_menu();
        ///Prentar út fyrstu Order í activeOrders sem er ekki með (bool baking = true)

        ///Check order as in making

        ///Check order as ready
    }
    else if(input == '3'){
        cout << "3. Check order as in making" << endl;
        ///Prenta út OrderesOrdersLocation_Name.txt
        string current_status = "ordered";
        string next_status = "making";
        change_status(current_status, next_status);

    }
    else if(input == '4'){
        cout << "4. Check order ready" << endl;
        ///Prenta út MakingOrdersLocation_name
        string current_status = "making";
        string next_status = "ready";
        change_status(current_status, next_status);


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
    ///Lesa active orders inn á vector
    baker_service.read_orders(vectors, status, location_name);

    cout << vectors.orders_list[0] << endl;
}

void BakerUI::check_in_making(int choice, Vectors& vectors){
    vectors.orders_list[choice-1].set_baking_status(true);
}

void BakerUI::change_status(string current_status, string next_status){
    print_orders(vectors,current_status);
    ///Velja nr. af order sem þú vilt merkja sem "in making"
    int choice = 0;
    cin >> choice;
    /// tengja niður á við og fá til að virka
    vectors.orders_list[choice - 1].set_baking_status(true);
    baker_service.check_in_making(vectors, location_name, current_status, next_status);

    main_menu();
}
