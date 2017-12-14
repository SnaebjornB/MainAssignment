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

Vectors Baker_repo::read_orders(Vectors& vectors, string location_name){
    ///Opna ActiveOrdersLocation_Name.txt og lesa inn i vector

    return vectors;
}
