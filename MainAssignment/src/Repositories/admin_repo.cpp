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
    else{
        ///Throw error
    }

}

Vectors Admin_Repo::read_topping(Vectors& vectors){
    ifstream fin;
    ofstream fout;
    fin.open("Toppings.txt");
    if(fin.is_open()){
        while(!fin.eof()){
            fin >> topping;
            vectors.topping_list.push_back(topping);
        }
        fin.close();
    }
    fout.open("Toppings.txt", ios::trunc);
    fout.close();

    return vectors;
}

void Admin_Repo::put_back_topping(Vectors& vectors){
    ofstream fout;
    fout.open("Toppings.txt", ios::app);

    if(fout.is_open()){
        if (vectors.topping_list.size() > 0){
            for (unsigned int i = 0; i < vectors.topping_list.size(); i++){
                vectors.topping_list[i].set_topping_helper(false);
                fout << vectors.topping_list[i];
            }
        }
    fout.close();
    }
    vectors.topping_list.clear();
}

