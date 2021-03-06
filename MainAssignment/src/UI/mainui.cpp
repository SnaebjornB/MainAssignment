#include "mainui.h"

MainUI::MainUI()
{
    //ctor
}

void MainUI::main_menu(){
    cout << "What department do you belong to?" << endl
         << "---------------------------------" << endl
         << "1. Admin" << endl
         << "2. Salesperson" << endl
         << "3. Baker" << endl
         << "4. Delivery" << endl << endl
         << "Please input the corresponding number: ";
    cin >> input;
    input_checker(input);
}

void MainUI::input_checker(char input){
    if(input == '1'){
        adminui.main_menu();
    }
    else if(input == '2'){
        salesui.location();
    }
    else if(input == '3'){
        bakerui.location();
    }
    else if(input == '4'){
        deliveryui.location();
    }
    else{
        cout << "Wrong Input.. Please try again" << endl;
        main_menu();
    }
}
