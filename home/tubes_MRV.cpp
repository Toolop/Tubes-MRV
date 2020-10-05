#include<iostream>
#include<stdlib.h>
#include <fstream>
using namespace std;

//global vairab
int pilihanSPl;
int pilihaninput;
int pilihandeterminan;
int menunya;
int m, n;

//Proses Menu 1 = SPL
void Gauss(){

}
void Gauss_jordan(){

}
void SPLBalikan(){

}
void krammer(){

}

//
//--inputSPL

//proses menu 2 = Determinan
void Reduksi_Baris(){

}
void Kofaktor (){

}


// prosesinvers
void Invers(){

}
//

void inputSPL(){
    cin>>m>>n;
    float a[m][n];
    float b[m];
    for (int i = 0; i < m; i++){\
        for (int j = 0; j < n;j++){
            cin>>a[i][j];
        }
        cin>>b[i];
    }
    switch (pilihanSPl){
    case 1:
        Gauss();
    break;
    case 2:
        Gauss_jordan();
    break;
    case 3:
        SPLBalikan();
    break;
    case 4:
        krammer();
    break;
    }
}

void inputSplFile(){

}

//--inputDeterminan
void inputDet(){
    int n;
    cin>>n;
    float a[n][n];
    for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
        cin>>a[i][j];
        }
    }
}

void inputdetfile(){

}
void inputInvers(){
    int n;
    cin>>n;
    float a[n][n];
    for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
        cin>>a[i][j];
        }
    }
}
void inputfileInvers(){

}



//--cara pilih--
void carainput(){
    system("clear");
    cout<<"1. Input konsol"<<endl;
    cout<<"2. Input File"<<endl;
    cout<<"Pilih cara input file cara 1 atau 2 = ";
    cin>>pilihaninput;
    if (menunya == 1){
        if (pilihaninput == 1){
            inputSPL();
        }
        else
            inputSplFile();
    }
    else if (menunya == 2){
         if (pilihaninput == 1){
            inputSPL();
        }
        else
            inputdetfile();
    }
    else if (menunya == 3){
        if(pilihaninput == 1){
            inputInvers();
        }
        else {
            inputfileInvers();
        }
    }
}


//--menu Sistem Persamaan Linear--
void submenuSPL(){
    system("clear");
    cout<<"1. Metode eleminasi Gauss "<<endl;
    cout<<"2. Metode eleminasi Gauss-Jordan"<<endl;
    cout<<"3. Metode matriks Balikan"<<endl;
    cout<<"4. Metode Crammer"<<endl;
    cout<<"Pilih menu (1-4) = ";
    cin>>pilihanSPl;
    carainput();
}
//--Menu Determinan--
void submenuinvers(){
    carainput();
}
//--Matriks Invers
void subDeterminan(){
    system("clear");
    int pilihan;
    cout<<"1. Reduksi Baris"<<endl;
    cout<<"2. Ekspansi Kofaktor"<<endl;
    cout<<"Pilih menu (1-4) = ";
    cin>>pilihan;
       carainput();
}

void checkpilihan(int pilih){
    switch(pilih){
        case 1:
            submenuSPL();
        break;
        case 2:
            subDeterminan();
        break;
        case 3:
            submenuinvers();
        break;
    }
}

//--Menu Utama--
void menu(){
    cout<<"1. Mencari Penyelesaian SPL "<<endl;
    cout<<"2. Mencari Determinan Matriks "<<endl;
    cout<<"3. Mencari Matriks Balikan"<<endl;
    cout<<"4. Keluar"<<endl;
    cout<<"Pilih menu (1-4) = ";
    cin>>menunya;
    checkpilihan(menunya);
}
//--main--
int main(){
    menu();
}
