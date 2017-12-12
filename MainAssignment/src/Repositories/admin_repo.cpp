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
    vectors.topping_list.clear();
    ifstream fin;
    ofstream fout;
    fin.open("Toppings.txt");
    if(fin.is_open()){
        while(fin >> topping){
            vectors.topping_list.push_back(topping);
        }
        fin.close();
    }

    return vectors;
}

void Admin_Repo::put_back_topping(Vectors& vectors){
    ofstream fout;
    fout.open("Toppings.txt", ios::trunc);
    fout.close();

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

void Admin_Repo::erase_topping(Vectors& vectors, unsigned int num_of_line){
    ofstream fout;
    fout.open("Toppings.txt", ios::trunc);
    fout.close();

    fout.open("Toppings.txt", ios::app);

    if(fout.is_open()){
        if (vectors.topping_list.size() > 0){
            for (unsigned int i = 0; i < vectors.topping_list.size(); i++){
                vectors.topping_list[i].set_topping_helper(false);
                if(i != (num_of_line - 1) ){
                fout << vectors.topping_list[i];
                }
            }
        }
    fout.close();
    }
    vectors.topping_list.clear();
}
