#include "salesperson_repo.h"

Salesperson_repo::Salesperson_repo()
{
    //ctor
}

Vectors Salesperson_repo::read_type(Vectors& vectors, string type){
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
void Salesperson_repo::get_base_price(Pizza& pizza){
    ifstream fin;
    fin.open("margaritaPrice.txt");
    pizza.set_size_helper(false);
    if(fin.is_open()){
        fin >> pizza;
        cout << pizza;
    }
    fin.close();
}
