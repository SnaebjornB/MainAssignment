#include "admin_repo.h"

Admin_Repo::Admin_Repo()
{
    //ctor
}

void Admin_Repo::write_topping(Topping topping){
    topping.set_topping_helper(false);
    ofstream fout;
    fout.open("Toppings.txt", ios::app);

    if(fout.is_open()){
        fout << topping;
        fout.close();
    }
}


