#include "ToppingRepository.h"

ToppingRepository::ToppingRepository()
{
    //ctor
}

void ToppingRepository::add_allowed_topping(Topping& topping){
    ofstream fout;
    fout.open("Allowed_Topping.txt", ios::app);
    if(fout.is_open()){
        fout << topping;
        fout.close();
    }
    else{
        ///Throw error
    }
}
