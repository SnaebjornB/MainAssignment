#include "deliveryui.h"

DeliveryUI::DeliveryUI()
{
    //ctor
}

void DeliveryUI::location() {
    cout << "pick your location" << endl;
    //cin << "location";
    main_menu();
}

void DeliveryUI::main_menu(){
    cout << "What do you want to do?" << endl
         << "-----------------------" << endl
         << "1. Get a list of all orders" << endl
         << "2. Get a list of ready orders" << endl
         << "3. Get a specific order" << endl
         << "4. Check order to paid" << endl
         << "5. Check order to done" << endl
         << "c. Change location " << endl << endl
         << "Please insert the corresponding number: ";
    cin >> input;
    main_input_checker(input);
}

void DeliveryUI::main_input_checker(char input){
    if(input == '1'){
        cout << "1. Get list of all orders" << endl;                            ///vantar
    }
    else if(input == '2'){
        cout << "2. Get list of ready orders" << endl;                          ///vantar
    }
    else if(input == '3'){
        cout << "3. get specific order" << endl;                                ///vantar
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
