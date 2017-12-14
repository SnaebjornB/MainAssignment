#include "bakerui.h"

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::location() {
    print_locations();
    cout << "pick your location: ";
    string location_name;
    unsigned int num_of_location;
    cin >> num_of_location;
    ///Velja nafn númer num_of_location
    location_name = vectors.locations_list[num_of_location-1];

    cout << "You chose: " << location_name << endl;

    main_menu(location_name);
}
void BakerUI::main_menu(string location_name){

    cout << "What do you want to do?" << endl
         << "-----------------------" << endl
         << "1. Get list of all orders" << endl
         << "2. Show next order to make" << endl
         << "3. Check order as in making" << endl
         << "4. Check order as ready" << endl
         << "c. change location " << endl << endl
         << "Please insert the corresponding number: ";
    cin >> input;
    main_input_checker(input, location_name);
}

void BakerUI::main_input_checker(char input, string location_name){
    if(input == '1'){
        cout << "1. Get list of all orders" << endl;
        ///Prenta út ActiveOrdersLocation_Name.txt
        string status = "ordered";
        print_orders(location_name, status);
        ///Prenta út MakingOrdersLocation_name
        status = "making";
        print_orders(location_name, status);

    }
    else if(input == '2'){
        cout << "2. Show next order to make" << endl;
        ///Prentar út fyrstu Order í activeOrders sem er ekki með (bool baking = true)

        ///Check order as in making

        ///Check order as ready
    }
    else if(input == '3'){
        cout << "3. Check order as in making" << endl;
        ///Prenta út OrderesOrdersLocation_Name.txt
        string status = "ordered";
        print_orders(location_name, status);
        ///Velja nr. af order sem þú vilt merkja sem "in making"

    }
    else if(input == '4'){
        cout << "4. Check order ready" << endl;
        ///Prenta út MakingOrdersLocation_name
        string status = "making";
        print_orders(location_name, status);

        ///Velja nr. af order sem þú vilt merkja sem "ready"

    }
    else if(input == 'c' || input == 'C'){
        location();
    }
    else{
        cout << endl << "Invalid input! Please choose again." << endl;
       main_menu(location_name);
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

void BakerUI::print_orders(string& location_name, string& status){
    ///Lesa active orders inn á vector
    baker_service.read_orders(vectors, location_name, status);
}
