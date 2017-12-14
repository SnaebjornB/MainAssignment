#include "admin_repo.h"

Admin_Repo::Admin_Repo()
{
    //ctor
}

void Admin_Repo::write_topping(Topping topping){
    topping.set_helper(false);
    ofstream fout;
    fout.open("topping.txt", ios::app);

    if(fout.is_open()){
        fout << topping;
        fout.close();
    }
    else{
        
    }
}



Vectors Admin_Repo::read_type(Vectors& vectors, string type){
    ///Nafnið á skranni sem við viljum opna
    string filename = type;
    string txt = ".txt";
    filename.append(txt);
    ifstream fin;
    ofstream fout;

    fin.open((filename).c_str());
    if(fin.is_open()){
        if(type == "topping"){
            vectors.topping_list.clear();
            while(fin >> topping){
                vectors.topping_list.push_back(topping);
            }
        }
        else if(type == "sides"){
            vectors.sides_list.clear();
            while(fin >> sides){
                vectors.sides_list.push_back(sides);
            }
        }
        else if(type == "pizza_menu"){
            vectors.pizza_menu_list.clear();
            while(fin >> menu_pizza){
                vectors.pizza_menu_list.push_back(menu_pizza);
            }
        }
        fin.close();
    }

    return vectors;
}

void Admin_Repo::put_back_type(Vectors& vectors, string type){
    string txt = ".txt";
    string filename = type;
    filename.append(txt);
    ofstream fout;
    fout.open((filename).c_str(), ios::trunc);
    fout.close();

    fout.open((filename).c_str(), ios::app);

    if(fout.is_open()){
        if(type == "topping"){
            if (vectors.topping_list.size() > 0){
                for (unsigned int i = 0; i < vectors.topping_list.size(); i++){
                    vectors.topping_list[i].set_helper(false);
                    fout << vectors.topping_list[i];
                }
            }
        }
        else if(type == "sides"){
            if (vectors.sides_list.size() > 0){
                for (unsigned int i = 0; i < vectors.sides_list.size(); i++){
                    vectors.sides_list[i].set_helper(false);
                    vectors.sides_list[i].set_write_helper (true);
                    fout << vectors.sides_list[i];
                }
            }
        }
        else if(type == "pizza_menu"){
            if (vectors.pizza_menu_list.size() > 0){
                for (unsigned int i = 0; i < vectors.pizza_menu_list.size(); i++){
                    vectors.pizza_menu_list[i].set_helper(false);
                    fout << vectors.pizza_menu_list[i];
                }
            }
        }
    fout.close();
    }
    vectors.topping_list.clear();
}

void Admin_Repo::erase_type(Vectors& vectors, unsigned int num_of_line, string type){
    string txt = ".txt";
    string filename = type;
    filename.append(txt);

    ofstream fout;
    fout.open((filename).c_str(), ios::trunc);
    fout.close();

    fout.open((filename).c_str(), ios::app);

    if(fout.is_open()){
        if(type == "topping"){
            if (vectors.topping_list.size() > 0){
                for (unsigned int i = 0; i < vectors.topping_list.size(); i++){
                    vectors.topping_list[i].set_helper(false);
                    if(i != (num_of_line - 1) ){
                        fout << vectors.topping_list[i];
                    }
                }
            }
            vectors.topping_list.clear();
        }
        else if(type == "sides"){
            if (vectors.sides_list.size() > 0){
                for (unsigned int i = 0; i < vectors.sides_list.size(); i++){
                    vectors.sides_list[i].set_helper(false);
                    vectors.sides_list[i].set_write_helper (true);
            
                    
                    if(i != (num_of_line - 1) ){
                        fout << vectors.sides_list[i];
                    }
                }
            }
            vectors.sides_list.clear();
        }
        else if(type == "pizza_menu"){
            if (vectors.pizza_menu_list.size() > 0){
                for (unsigned int i = 0; i < vectors.pizza_menu_list.size(); i++){
                    vectors.pizza_menu_list[i].set_helper(false);
                    if(i != (num_of_line - 1) ){
                        fout << vectors.pizza_menu_list[i];
                    }
                }
            }
            vectors.pizza_menu_list.clear();
        }
        fout.close();
    }
}

void Admin_Repo::write_sides(Sides& sides){
    sides.set_write_helper(true);
    sides.set_helper(false);
    
    ofstream fout;
    fout.open("sides.txt", ios::app);

    if(fout.is_open()){
        fout << sides;
        fout.close();
    }
    else{
        ///Throw error
    }
}

void Admin_Repo::write_menu_pizza(Menu_Pizza& menu_pizza){
    menu_pizza.set_helper(false);
    ofstream fout;
    fout.open("pizza_menu.txt", ios::app);

    if(fout.is_open()){
        fout << menu_pizza;
        fout.close();
    }
    else{
        ///Throw error
    }
}

void Admin_Repo::write_location(string location){
    //sides.set_helper(false);
    ofstream fout;
    fout.open("locations.txt", ios::app);
    if(fout.is_open()){
        fout << location << endl;
        fout.close();
    }
    else{
        ///Throw error
    }
}

void Admin_Repo::write_price_margarita(Pizza& pizza) {
    ofstream fout;
    fout.open("margaritaPrice.txt");
    pizza.set_size_helper(false);
    if(fout.is_open()) {
        fout << pizza;
        fout.close();
    }
    else{
        //throw error
    }
}

