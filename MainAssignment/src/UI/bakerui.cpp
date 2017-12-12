#include "bakerui.h"

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::location() {
    cout << "pick your location" << endl;
    //cin << "location";
    main_menu();
}
void BakerUI::main_menu(){
    
    cout << "What do you want to do?" << endl
         << "-----------------------" << endl
         << "1. Get list of all orders" << endl
         << "2. show next order" << endl
         << "3. Check order in making" << endl
         << "4. Check order ready" << endl
         << "c. change location " << endl << endl
         << "Please insert the corresponding number: ";
    cin >> input;
    main_input_checker(input);
}

void BakerUI::main_input_checker(char input){
    if(input == '1'){
        cout << "1" << endl;
    }
    else if(input == '2'){
        cout << "2" << endl;
    }
    else if(input == '3'){
        cout << "3" << endl;
    }
    else if(input == '4'){
        cout << "4" << endl;
    }
    else if(input == 'c' || input == 'C'){
        location();
    }
    else{
        cout << endl << "Invalid input! Please choose again." << endl;
       main_menu();
    }
}
