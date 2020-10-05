#include<iostream>
using namespace std;


//--menu Sistem Persamaan Linear--
void submenuSPL(){
    cout<<"1. Mencari dengan  "<<endl;
    cout<<"2. Mencari Determinan Matriks "<<endl;
    cout<<"3. Mencari Matriks Balikan"<<endl;
    cout<<"Pilih menu (1-4) = ";
}
//--Menu Determinan--
void submenuDet(){
    cout<<"Hehe";
}

//--Menu Utama--
void menu(){
    int pilih;
    cout<<"1. Mencari Penyelesaian SPL "<<endl;
    cout<<"2. Mencari Determinan Matriks "<<endl;
    cout<<"3. Mencari Matriks Balikan"<<endl;
    cout<<"Pilih menu (1-4) = ";
    cin>>pilih;
    switch(pilih){
        case 1:
            submenuSPL();
        break;
        case 2:
            submenuDet();
        break;
        case 3:

    }
}

//--main--
int main(){
    menu();
}
