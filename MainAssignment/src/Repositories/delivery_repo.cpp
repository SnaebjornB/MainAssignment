#include "delivery_repo.h"

Delivery_repo::Delivery_repo()
{
    //ctor
}

Vectors Delivery_repo::read_locations(Vectors& vectors){
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

Vectors Delivery_repo::read_orders(Vectors& vectors, string& location_name, string status){
    string txt = ".txt";
    status.append(location_name);
    status.append(txt);

    int i = 0;

    ifstream fin;
    ofstream fout;

    fin.open((status).c_str());
    if(fin.is_open()){
        vectors.orders_list.clear();
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

Vectors Delivery_repo::change_order_status(Vectors& vectors, string& location_name, string& current_status, string next_status){

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
