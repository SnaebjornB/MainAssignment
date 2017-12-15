#include "baker_repo.h"

Baker_repo::Baker_repo()
{
    //ctor
}

Vectors Baker_repo::read_locations(Vectors& vectors){
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

Vectors Baker_repo::read_orders(Vectors& vectors, string& location_name, string status){
    ///Opna ActiveOrdersLocation_Name.txt og lesa inn i vector.
    ///
    ///Þetta prentar út innihald skjalsins, eina línu í einu. Útfæra að það lesi það inn í vektor og skili honum.
    /// Búa til vektor sem inniheldur Orders og skila honum svo

    string txt = ".txt";
    status.append(location_name);
    status.append(txt);

    int i = 0;          ///Debugger
    cout << i << endl; ///Debugger

    ifstream fin;
    ofstream fout;

    fin.open((status).c_str());   ///(test).c_str()
    if(fin.is_open()){
        vectors.orders_list.clear();
        orders.set_in_helper(false);
        while(fin >> orders){
            if(fin.eof()){ /// líklega óþarfi
                break;
            }
            orders.set_in_helper(true);
            fin >> orders;
            vectors.orders_list.push_back(orders);  ///Breyta í orders_list og line -> orders ///locations_list
            vectors.orders_list[i].set_helper(true);
            orders.set_in_helper(false);
            i++;
        }
    }
        fin.close();
    return vectors;
}

Vectors Baker_repo::change_order_status(Vectors& vectors, string& location_name, string& current_status, string next_status){

    string txt = ".txt";
    current_status.append(location_name);
    current_status.append(txt);

    next_status.append(location_name);
    next_status.append(txt);

    ifstream fin;
    ofstream fout ,fileout;

    fout.open((current_status).c_str(), ios::trunc);
    fout.close();
    fout.open((current_status).c_str(), ios::app);
    fileout.open((next_status).c_str(), ios::app);

        for(unsigned int j = 0; j < vectors.orders_list.size(); j++){
            if(!(vectors.orders_list[j].get_baking_status())){
                if(fout.is_open()){
                    vectors.orders_list[j].set_helper(false);
                    fout << vectors.orders_list[j];
                }
            }
            else if(vectors.orders_list[j].get_baking_status()){
                if(fileout.is_open()){
                    vectors.orders_list[j].set_helper(false);
                    fileout << vectors.orders_list[j];
                }
            }
        }
    fout.close();
    fileout.close();
    return vectors;
}

/*
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
    */
