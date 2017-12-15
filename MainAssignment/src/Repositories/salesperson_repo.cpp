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
    }
    fin.close();
}

void Salesperson_repo::write_order(Orders& orders, string location_name){
    string txt = ".txt";
    string status = "ordered";

    status.append(location_name);
    status.append(txt);

    orders.set_helper(false);
    ofstream fout;
    fout.open((status).c_str(), ios::app);

    if(fout.is_open()){
        fout << orders;
        fout.close();
    }
    else{
        ///Throw error
    }
}

Vectors Salesperson_repo::read_locations(Vectors& vectors){
    ///Opna locations.txt lesa inn í vector
    ifstream fin;
    ofstream fout;
    string name;
    fin.open("locations.txt");
    if(fin.is_open()){
        vectors.locations_list.clear();
        while(getline(fin, name)){                             ///fin >> name
            vectors.locations_list.push_back(name);
        }
        fin.close();
    }

    return vectors;
}

Vectors Salesperson_repo::read_orders(Vectors& vectors, string& location_name, string status){
    string txt = ".txt";
    status.append(location_name);
    status.append(txt);

    int i = 0;

    ifstream fin;
    ofstream fout;

    fin.open((status).c_str());
    if(fin.is_open()){
        //vectors.orders_list.clear();
        orders.set_in_helper(false);
        while(fin >> orders){
            if(fin.eof()){
                break;
            }
            orders.set_in_helper(true);
            fin >> orders;
            vectors.orders_list.push_back(orders);
            vectors.orders_list[i].set_helper(true);
            orders.set_in_helper(false);
            i++;
        }
    }
        fin.close();
    return vectors;
}
