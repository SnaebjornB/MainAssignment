#include "deliveryui.h"
#include "mainui.h"

DeliveryUI::DeliveryUI()
{
    //ctor
}

void DeliveryUI::location() {
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

void DeliveryUI::main_menu(){
    cout << "What do you want to do?" << endl
         << "-----------------------" << endl
         << "1. Get a list of all orders" << endl
         << "2. Get a list of ready orders" << endl
         << "3. Get a specific order" << endl
         << "4. Check order to paid" << endl
         << "5. Check order to delivered" << endl
         << "Input q to logout" << endl << endl
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
        check_order_paid();
    }
    else if(input == '5'){
        check_order_delivered();
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

void DeliveryUI::print_all_orders(){
    string ordered = "ordered", making = "making", ready = "ready";
    int choice = 0;

    delivery_service.read_orders(vectors, ordered, location_name);
    delivery_service.read_orders(vectors, making, location_name);
    delivery_service.read_orders(vectors, ready, location_name);
    int checker = (int) vectors.pizza_menu_list.size();

    if (vectors.orders_list.size() > 0){
        for(unsigned int i = 0; i < vectors.orders_list.size(); i++){
            cout << (i+1) << ". " << vectors.orders_list[i].get_name()
             << " " << vectors.orders_list[i].get_phone_number() << endl;
        }

        do {
            cout << "Which order do you need to view? ";
            cin >> choice;
            if(choice < 1 || choice > checker){
                cout << "Invalid input! Try again." << endl;
            }
        }while(choice < 1 || choice > checker);

        cout << vectors.orders_list[choice - 1] << endl;

        current_order.clear();
        current_order.push_back(vectors.orders_list[choice - 1]);
        vectors.orders_list.clear();
    }
    else{
        cout << "Could not find any orders!" << endl;
    }

    main_menu();
}

void DeliveryUI::print_ready_orders(){
    string ready = "ready";
    int choice = 0;

    delivery_service.read_orders(vectors, ready, location_name);
    if (vectors.orders_list.size() > 0){
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
    }
    else{
        cout << "Could not find any orders!" << endl;
    }
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
        if(phone_number == vectors.orders_list[i].get_phone_number()){
            cout << vectors.orders_list[i] << endl;
            current_order.push_back(vectors.orders_list[i]);
        }
        else{
            break;
        }
    }
    vectors.orders_list.clear();

    main_menu();
}

void DeliveryUI::check_order_paid(){
    string phone_number, ordered = "ordered", making = "making", ready = "ready";
    int choice = 0;
    if(current_order.size() > 0){
        cout << "Is this the order you want to check paid? (y/n) " << endl << current_order[0] << endl;
        cin >> input;
        phone_number = current_order[0].get_phone_number();
        if (input == 'y' || input == 'Y'){
            for(unsigned int i = 0; i < vectors.orders_list.size(); i++){
                if (phone_number.compare(vectors.orders_list[i].get_phone_number())){
                    vectors.orders_list[i].set_paid_status(true);
                }
            }
        }
        else{
        delivery_service.read_orders(vectors, ordered, location_name);
        delivery_service.read_orders(vectors, making, location_name);
        delivery_service.read_orders(vectors, ready, location_name);
        cout << "Please select the order you want to mark paid: " << endl;
        for(unsigned int i = 0; i < vectors.orders_list.size(); i++){
            cout << (i+1) << ". " << vectors.orders_list[i].get_name()
             << " " << vectors.orders_list[i].get_phone_number() << endl;
        }
        cout << "input: ";
        cin >> choice;

        vectors.orders_list[choice -1].set_paid_status(true);
    }
    }
    else{
        delivery_service.read_orders(vectors, ordered, location_name);
        delivery_service.read_orders(vectors, making, location_name);
        delivery_service.read_orders(vectors, ready, location_name);

        cout << "Please select the order you want to mark paid: " << endl;

        for(unsigned int i = 0; i < vectors.orders_list.size(); i++){
            cout << (i+1) << ". " << vectors.orders_list[i].get_name()
             << " " << vectors.orders_list[i].get_phone_number() << endl;
        }

        cout << "input: ";
        cin >> choice;

        int checker = (int) vectors.orders_list.size();

        do {
            cout << "input: ";
            cin >> choice;
            if(choice < 1 || choice > checker){
                cout << "Invalid input! Try again." << endl;
            }
        }while(choice < 1 || choice > checker);

        vectors.orders_list[choice -1].set_paid_status(true);
    }

    main_menu();
}

void DeliveryUI::check_order_delivered(){
    string phone_number, ordered = "ordered", making = "making", ready = "ready";
    int choice = 0;
    if(current_order.size() > 0){
        cout << "Is this the order you want to check paid? (y/n) " << endl << current_order[0] << endl;
        cin >> input;
        phone_number = current_order[0].get_phone_number();
        if (input == 'y' || input == 'Y'){
            for(unsigned int i = 0; i < vectors.orders_list.size(); i++){
                if (phone_number.compare(vectors.orders_list[i].get_phone_number())){
                    vectors.orders_list[i].set_paid_status(true);
                }
            }
        }
        else{
        delivery_service.read_orders(vectors, ordered, location_name);
        delivery_service.read_orders(vectors, making, location_name);
        delivery_service.read_orders(vectors, ready, location_name);
        cout << "Please select the order you want to mark paid: " << endl;
        for(unsigned int i = 0; i < vectors.orders_list.size(); i++){
            cout << (i+1) << ". " << vectors.orders_list[i].get_name()
             << " " << vectors.orders_list[i].get_phone_number() << endl;
        }
        cout << "input: ";
        cin >> choice;

        vectors.orders_list[choice -1].set_delivered_status(true);
    }
    }
    else{
        delivery_service.read_orders(vectors, ordered, location_name);
        delivery_service.read_orders(vectors, making, location_name);
        delivery_service.read_orders(vectors, ready, location_name);

        cout << "Please select the order you want to mark paid: " << endl;

        for(unsigned int i = 0; i < vectors.orders_list.size(); i++){
            cout << (i+1) << ". " << vectors.orders_list[i].get_name()
             << " " << vectors.orders_list[i].get_phone_number() << endl;
        }

        cout << "input: ";
        cin >> choice;

        int checker = (int) vectors.orders_list.size();

        do {
            cout << "input: ";
            cin >> choice;
            if(choice < 1 || choice > checker){
                cout << "Invalid input! Try again." << endl;
            }
        }while(choice < 1 || choice > checker);

        vectors.orders_list[choice -1].set_delivered_status(true);
    }

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
