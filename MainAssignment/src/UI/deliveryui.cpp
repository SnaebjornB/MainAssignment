#include "deliveryui.h"

DeliveryUI::DeliveryUI()
{
    //ctor
}

void DeliveryUI::location() {
    print_locations();
    cout << "pick your location: ";
    unsigned int num_of_location;
    cin >> num_of_location;
    ///Velja nafn númer num_of_location
    location_name = vectors.locations_list[num_of_location-1];

    main_menu();
}

void DeliveryUI::main_menu(){
    cout << "What do you want to do?" << endl
         << "-----------------------" << endl
         << "1. Get a list of all orders" << endl
         << "2. Get a list of ready orders" << endl
         << "3. Get a specific order" << endl
         << "4. Check order to paid" << endl
         << "5. Check order to delivered" << endl
         << "c. Change location " << endl << endl
         << "Please insert the corresponding number: ";
    cin >> input;
    main_input_checker(input);
}

void DeliveryUI::main_input_checker(char input){
    if(input == '1'){
        print_all_orders();
    }
    else if(input == '2'){
        print_ready_orders();
    }
    else if(input == '3'){
        print_specific_order();
    }
    else if(input == '4'){
        cout << "4. Check order to paid" << endl;                               ///vantar
    }
    else if(input == '5'){
        cout << "5. Check order to done" << endl;                               ///vantar
    }
    else if(input == 'c' || input == 'C'){
        location();
    }
    else{
        cout << endl << "Invalid input! Please choose again." << endl;
        main_menu();
    }
}

void DeliveryUI::print_all_orders(){
    string ordered = "ordered", making = "making", ready = "ready";
    int choice = 0;

    delivery_service.read_orders(vectors, ordered, location_name);
    delivery_service.read_orders(vectors, making, location_name);
    delivery_service.read_orders(vectors, ready, location_name);

    for(unsigned int i = 0; i < vectors.orders_list.size(); i++){
        cout << (i+1) << ". " << vectors.orders_list[i].get_name()
             << " " << vectors.orders_list[i].get_phone_number() << endl;
    }
    cout << "Which order do you need to view? ";
    cin >> choice;

    cout << vectors.orders_list[choice - 1] << endl;

    current_order.clear();

    current_order.push_back(vectors.orders_list[choice - 1]);

    vectors.orders_list.clear();

    main_menu();
}

void DeliveryUI::print_ready_orders(){
    string ready = "ready";
    int choice = 0;

    delivery_service.read_orders(vectors, ready, location_name);

    for(unsigned int i = 0; i < vectors.orders_list.size(); i++){
        cout << (i+1) << ". " << vectors.orders_list[i].get_name()
             << " " << vectors.orders_list[i].get_phone_number() << endl;
    }

    cout << "Which order do you need to view? ";
    cin >> choice;

    cout << vectors.orders_list[choice - 1] << endl;

    current_order.clear();

    current_order.push_back(vectors.orders_list[choice - 1]);

    vectors.orders_list.clear();

    main_menu();
}

void DeliveryUI::print_specific_order(){
    string phone_number, ordered = "ordered", making = "making", ready = "ready";
    current_order.clear();
    cout << "Phone number: ";
    cin >> phone_number;

    delivery_service.read_orders(vectors, ordered, location_name);
    delivery_service.read_orders(vectors, making, location_name);
    delivery_service.read_orders(vectors, ready, location_name);

    for(unsigned int i = 0; i < (vectors.orders_list.size()); i++){
        if(phone_number.compare(vectors.orders_list[i].get_phone_number())){// == vectors.orders_list[i].get_phone_number()){
            cout << vectors.orders_list[i] << endl;
            current_order.push_back(vectors.orders_list[i]);
        }
    }
    vectors.orders_list.clear();

    main_menu();
}

void DeliveryUI::print_locations(){
    ///lesa loactions.txt inn í vector
    delivery_service.read_locations(vectors);

    ///Prenta út vector
    for(unsigned int i = 0; i < vectors.locations_list.size(); i++){
        cout << (i+1) << ". " << vectors.locations_list[i] << endl;
    }
}
