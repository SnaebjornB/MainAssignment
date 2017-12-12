#include "admin_repo.h"

Admin_Repo::Admin_Repo()
{
    //ctor
}

void Admin_Repo::write_topping(Topping topping){
    topping.set_helper(false);
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

Vectors Admin_Repo::read_type(Vectors& vectors, string type){
    ///Nafnið á skranni sem við viljum opna
    string filename = type;
    string txt = ".txt";
    filename.append(txt);
    cout << "3";
    ifstream fin;
    ofstream fout;

    fin.open((filename).c_str());
    if(fin.is_open()){
        cout << "bobblem";
        if(type == "topping"){
            vectors.topping_list.clear();
            cout << "Whaaaaaaat!!!" << endl;
            while(fin >> topping){
                vectors.topping_list.push_back(topping);
            }
        }
        else if(type == "sides"){
            vectors.sides_list.clear();
            cout << "4";
            while(fin >> sides){
                int i = 0;
                vectors.sides_list.push_back(sides);
                cout << vectors.sides_list[i];
                i++;
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
                    fout << vectors.sides_list[i];
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
        if (vectors.topping_list.size() > 0){
            for (unsigned int i = 0; i < vectors.topping_list.size(); i++){
                vectors.topping_list[i].set_helper(false);
                if(i != (num_of_line - 1) ){
                fout << vectors.topping_list[i];
                }
            }
        }
    fout.close();
    }
    vectors.topping_list.clear();
}

void Admin_Repo::write_sides(Sides& sides){
    sides.set_helper(false);
    ofstream fout;
    fout.open("Sides.txt", ios::app);

    if(fout.is_open()){
        fout << sides;
        fout.close();
    }
    else{
        ///Throw error
    }
}
