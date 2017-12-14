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

Vectors Baker_repo::read_orders(Vectors& vectors, string& location_name, string& status){
    ///Opna ActiveOrdersLocation_Name.txt og lesa inn i vector.
    ///
    ///Þetta prentar út innihald skjalsins, eina línu í einu. Útfæra að það lesi það inn í vektor og skili honum.
    /// Búa til vektor sem inniheldur Orders og skila honum svo
    /*
    string txt = ".txt";
    status.append(location_name);
    status.append(txt);
    */

    int i = 0;          ///Debugger
    cout << i << endl; ///Debugger
    string line; ///Debug  ///Eyða þegar er komið i lag

    ifstream fin;
    ofstream fout;

    fin.open("orders.txt");   ///(test).c_str()
    if(fin.is_open()){
        cout << "opnar skra" << endl; ///debugger
        vectors.orders_list.clear();
        cout << "hreinsar vektor" << endl; ///debugger
        while(fin >> orders){ ///  getline(fin, line)  ///Skipta a þessum skilyrðum inn i while-loopinu
            cout << "kemst inn i loop" << endl; ///Debugger
            vectors.orders_list.push_back(orders);  ///Breyta í orders_list og line -> orders ///locations_list
            cout << vectors.orders_list[i] << endl; ///Breyta í orders_list
            i++; ///Debugger
        }
        fin.close();
        cout << "lokar skra" << endl; ///debugger
    }
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
