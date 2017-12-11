#include "deliveryui.h"

DeliveryUI::DeliveryUI()
{
    //ctor
}

void DeliveryUI::main_menu(){
    cout << string(50, '\n');
    cout << "What do you want to do?" << endl
         << "-----------------------" << endl
         << "1. " << endl
         << "2. " << endl
         << "3. " << endl
         << "Please insert the corresponding number: ";
    cin >> input;
    input_checker(input);
}

void DeliveryUI::input_checker(char input){
    if(input == '1'){
        cout << "1" << endl;
    }
    else if(input == '2'){
        cout << "2" << endl;
    }
    else if(input == '3'){
        cout << "3" << endl;
    }
    else{
        cout << "nope" << endl;
    }
}
