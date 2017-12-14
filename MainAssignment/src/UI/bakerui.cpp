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
    ///Velja nafn n�mer num_of_location
    location_name = vectors.locations_list[num_of_location-1];

    baker_service.set_private_location_name(location_name);

    main_menu();
}
void BakerUI::main_menu(){

    cout << "What do you want to do?" << endl
         << "-----------------------" << endl
         << "1. Get list of all orders" << endl
         << "2. Show next order to make" << endl
         << "3. Check order as in making" << endl
         << "4. Check order as ready" << endl
         << "c. change location " << endl << endl
         << "Please insert the corresponding number: ";
    cin >> input;
    main_input_checker(input);
}

void BakerUI::main_input_checker(char input){
    if(input == '1'){
        cout << "1. Get list of all orders" << endl;
        ///Prenta �t ActiveOrdersLocation_Name.txt
        string status = "ordered";
        print_orders(status);
        ///Prenta �t MakingOrdersLocation_name
        status = "making";
        print_orders(status);

    }
    else if(input == '2'){
        cout << "2. Show next order to make" << endl;
        ///Prentar �t fyrstu Order � activeOrders sem er ekki me� (bool baking = true)

        ///Check order as in making

        ///Check order as ready
    }
    else if(input == '3'){
        cout << "3. Check order as in making" << endl;
        ///Prenta �t OrderesOrdersLocation_Name.txt
        string status = "ordered";
        print_orders(status);
        ///Velja nr. af order sem �� vilt merkja sem "in making"

    }
    else if(input == '4'){
        cout << "4. Check order ready" << endl;
        ///Prenta �t MakingOrdersLocation_name
        string status = "making";
        print_orders(status);

        ///Velja nr. af order sem �� vilt merkja sem "ready"

    }
    else if(input == 'c' || input == 'C'){
        location();
    }
    else{
        cout << endl << "Invalid input! Please choose again." << endl;
       main_menu();
    }
}

void BakerUI::print_locations(){
    ///lesa loactions.txt inn � vector
    baker_service.read_locations(vectors);

    ///Prenta �t vector
    for(unsigned int i = 0; i < vectors.locations_list.size(); i++){
        cout << (i+1) << ". " << vectors.locations_list[i] << endl;
    }
}

void BakerUI::print_orders(string& status){
    ///Lesa active orders inn � vector
    baker_service.read_orders(vectors, status);
}
