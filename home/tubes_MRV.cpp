#include<iostream>
#include<stdlib.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <cfloat>
using namespace std;

//global vairabel
int pilihanSPl;
int pilihaninput;
int pilihandeterminan;
int menunya;
int m, n;

//Proses Menu 1 = SPL
void Gauss(){
    int m;
    int n;
    cout<<"Masukkan Banyaknya baris (m) = ";
    cin>>m;
    cout<<"Masukkan banyak variabel (n) = ";
    cin>>n;
    float a[m][n];
    float b[m];
    cout<<endl<<"Mengisi Matriks = "<<endl;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cin>>a[i][j];
            }
            cin>>b[i];
        }

    int nol[n];
    float pengurang;
    int tuker = 0;
    float temp;
    bool penyelesaian = true;

    for (int i = 0; i < m; i++){
        for (int j = 0 ;j < m;j++){
            nol[j] = 0;
        }
        for(int j = 0; j < m; j ++){
            bool eselon = true;
            for(int z = 0; z< n; z++){
                if (eselon && a[j][z] == 0){
                    nol[j]++;
                }else {
                    eselon = false;
                }
            }
            if(nol[j] == n){
                penyelesaian = false;
                break;
            }
        }
        for (int j = 0; j < m-1; j++){
           for (int z= j+1; z < n;z++){
                if(nol[j]>nol[z]){
                    tuker++;
                    temp = nol[j];
                    nol[j] = nol[z];
                    nol[z] = temp;

                    temp = b[j];
                    b[j] = b[z];
                    b[z] = b[j];

                    for (int l = 0; l < n;l++){

                    temp = a[j][l];
                    a[j][l] = a[z][l];
                    a[z][l] = temp;

                    }
                }
            }
        }
        bool ditambah = true;
        for (int j = 0; j < m; j++){
                if(nol[i] == nol[j] && j > i){
                 for (int z = 0; z < n ;z++){
                    if(z == nol[i]){
                    pengurang = a[j][z]/ a[i][z];
                        if (pengurang < 0){
                            pengurang = pengurang * -1;
                        }
                     if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0){
                        ditambah = false;
                        b[j] = b[j] + (pengurang * b[i]);

                     }
                     else{
                        ditambah = true;
                        b[j] = b[j] - (pengurang * b[i]);
                        }
                    }
                    if (ditambah){
                        a[j][z] = a[j][z] - (pengurang * a[i][z]);
                    }
                    else{
                         a[j][z] = a[j][z] + (pengurang * a[i][z]);
                    }

                }
            }
        }

    }

        float x[n];

        if(penyelesaian){
            for (int i = 0; i < n; i++){
                x[i] = 0;
            }
            for (int i = m-1 ;i >= 0;i--){
                for(int j = n-1; j >= 0;j--){
                    if(j > i){
                        x[i] += (a[i][j] * x[j]);
                    }
                    else {
                        x[i] = (b[i] - x[i]) / a[i][j];
                        break;
                    }
                }
            }
            for (int i = 0;i < n; i++){
                if(isinf(b[i])||isnan(a[i][i])){
                    cout<<"Maaf tidak ada solusi di program ini"<<endl;
                    break;
                }
                else
                cout<<endl<<"x"<<i+1<<" = "<<x[i]<<endl;
            }
        cout<<endl<<endl;
        }else{
            if(b[n-1] != 0){
            cout<<endl<<"Tidak ada penyelesaian"<<endl;
            }
            else {
            cout<<endl<<"Solusi Banyak"<<endl;
            }
        }
}

void GaussFile(){
    int m;
    int n;
    string inputfile;
    cout<<"Masukkan nama file = ";
    cin>>inputfile;
    fstream file;
    file.open(inputfile.c_str());
    file>>m;
    file>>n;
    float a[m][n];
    float b[m];
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                file>>a[i][j];
            }
            file>>b[i];
        }

    int nol[n];
    float pengurang;
    int tuker = 0;
    float temp;
    bool penyelesaian = true;

    for (int i = 0; i < m; i++){
        for (int j = 0 ;j < m;j++){
            nol[j] = 0;
        }
        for(int j = 0; j < m; j ++){
            bool eselon = true;
            for(int z = 0; z< n; z++){
                if (eselon && a[j][z] == 0){
                    nol[j]++;
                }else {
                    eselon = false;
                }
            }
            if(nol[j] == n){
                penyelesaian = false;
                break;
            }
        }
        for (int j = 0; j < m-1; j++){
           for (int z= j+1; z < n;z++){
                if(nol[j]>nol[z]){

                    tuker++;
                    temp = nol[j];
                    nol[j] = nol[z];
                    nol[z] = temp;

                    temp = b[j];
                    b[j] = b[z];
                    b[z] = b[j];

                    for (int l = 0; l < n;l++){

                        temp = a[j][l];
                        a[j][l] = a[z][l];
                        a[z][l] = temp;

                    }
                }
            }
         }
        bool ditambah = true;
        for (int j = 0; j < m; j++){
                if(nol[i] == nol[j] && j > i){
                 for (int z = 0; z < n ;z++){
                    if(z == nol[i]){
                    pengurang = a[j][z]/ a[i][z];
                        if (pengurang < 0){
                            pengurang = pengurang * -1;
                        }
                     if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0){
                        ditambah = false;
                        b[j] = b[j] + (pengurang * b[i]);

                     }
                     else{
                        ditambah = true;
                        b[j] = b[j] - (pengurang * b[i]);
                        }
                    }
                    if (ditambah){
                        a[j][z] = a[j][z] - (pengurang * a[i][z]);
                    }
                    else{
                         a[j][z] = a[j][z] + (pengurang * a[i][z]);
                    }

                }
            }
        }

    }

        float x[n];

        if(penyelesaian){
            for (int i = 0; i < n; i++){
                x[i] = 0;
            }
            for (int i = m-1 ;i >= 0;i--){
                for(int j = n-1; j >= 0;j--){
                    if(j > i){
                        x[i] += (a[i][j] * x[j]);
                    }
                    else {
                        x[i] = (b[i] - x[i]) / a[i][j];
                        break;
                    }
                }
            }
            for (int i = 0;i < n; i++){
                if(isinf(b[i])||isnan(b[i])){
                    cout<<"Maaf tidak ada solusi di program ini"<<endl;
                    break;
                }
                else
                cout<<endl<<"x"<<i+1<<" = "<<x[i]<<endl;
            }
        cout<<endl<<endl;
        }else{
            if(b[n-1] != 0){
                cout<<endl<<"Tidak ada penyelesaian"<<endl;
            }
            else {
                cout<<endl<<"Solusi Banyak"<<endl;
            }
        }
}
void Gauss_jordan(){
    int m;
    int n;
    cout<<"Masukkan Banyaknya Baris (m)    = ";
    cin>>m;
    cout<<"Masukkan Banyaknya variabel (n) = ";
    cin>>n;
    float a[m][n];
    float b[m];
	cout<<"Mengisi matriks = "<<endl;
        for (int i = 0; i < m; i++){
            for (int j = 0; j< n; j++){
                cin>>a[i][j];
            }
            cin>>b[i];
        }

    int nol[n];
    bool penyelesaian = true;
    float pengurang;
    float temp;

    for (int i = 0; i < m; i++){
        for (int j = 0 ;j < m;j++){
            nol[j] = 0;
        }
        for(int j = 0; j < m; j ++){
            bool eselon = true;
            for(int z = 0; z< n; z++){
                if (eselon && a[j][z] == 0){
                    nol[j]++;
                }else {
                    eselon = false;
                }
            }
            if(nol[j] == n){
                penyelesaian = false;
                break;
            }
        }
        for (int j = 0; j < m-1; j++){
           for (int z= j+1; z < n;z++){
                if(nol[j]>nol[z]){

                    temp = nol[j];
                    nol[j] = nol[z];
                    nol[z] = temp;


                    temp = b[j];
                    b[j] = b[z];
                    b[z] = b[j];

                    for (int l = 0; l < n;l++){
                        temp = a[j][l];
                        a[j][l] = a[z][l];
                        a[z][l] = temp;

                    }
                }
            }
        }

        //reduksi dari atas
        for (int j = 0; j < m; j++){
            bool mines = false;
                if(nol[i] == nol[j] && j > i){
                 for (int z = 0; z < n ;z++){
                    //untuk mencari perkalian yang ada seperti r1 + xr2 mencari nilai x konstanta patokan dari i
                    if(z == nol[i]){
                    pengurang = a[j][z]/ a[i][z];
                        if (pengurang < 0){
                            pengurang = pengurang * -1;
                        }

                        if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0 ){
                        mines = true;
                            b[j] = b[j] + (pengurang * b[i]);
                        }
                        else{
                            mines = false;
                            b[j] = b[j] - (pengurang * b[i]);
                        }

                    }
                    //sampe sini nyari konstanta

                    //ini untuk mpengurangan apakah di tambah atau dikurang agar nol jika + - maka ditambah jika ++ atau -- maka dikurang
                    if (mines){
                        a[j][z] = a[j][z] + pengurang * a[i][z];
                    }
                    else{
                         a[j][z] = a[j][z] - pengurang * a[i][z];
                    }

                }
                    //untuk invernsya di bagi karena ini mulai dari nol
            }
        }

      if(penyelesaian){
        //membuat eselon tereduksi
      float makeone;
          for (int j = 0; j < n; j++){
                if(i == j && i != 0 ){
                    if(a[i][j] != 1 && a[i][j] != 0){
                      makeone = 1 / a[i][j];
                      for (int z = 0; z < n; z++){
                        a[j][z] = a[j][z] * makeone;

                    }b[j] = b[j] * makeone;

                 }
             }

            }
        }

        //end

}
    if(penyelesaian){
    for (int i = m-1; i > 0; i--){
           for (int j = 0; j < i; j++){
                bool mines = false;
                   for(int z = 0; z < n; z++){
                        if(z == nol[i]){
                            pengurang = a[j][z]/ a[i][z];

                            if (pengurang < 0){
                                pengurang = pengurang * -1;
                            }
                            if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0 ){
                            mines = true;
                             b[j] = b[j] + (pengurang * b[i]);
                            }
                            else{
                            mines = false;
                             b[j] = b[j] - (pengurang * b[i]);
                            }

                        }
                        if (mines){
                            a[j][z] = a[j][z] + pengurang * a[i][z];
                        }
                        else{
                            a[j][z] = a[j][z] - pengurang * a[i][z];
                        }

                    }
                        //untuk invernsya di bagi karena ini mulai dari nol
                }

        }
        }
        cout<<endl;

        if (penyelesaian){
            for (int i =0 ;i < n; i++){
                if(isinf(b[i])||isnan(b[i])){
                    cout<<"Maaf tidak ada solusi di program ini"<<endl;
                    break;
                }
                cout<<"nilai dari x"<<i+1<<" = "<<b[i]<<endl;
            }
        }
        else{
            if(b[n-1] != 0){
            cout<<"Tidak ada penyelesaian";
            }
            else {
            cout<<"Solusi Banyak";
            }
        }
}

void Gauss_jordanFile(){
    int m;
    int n;
    string inputfile;
    cout<<"Masukkan nama file = ";
    cin>>inputfile;
    fstream(file);
    file.open(inputfile.c_str());
    file>>m>>n;
    float a[m][n];
    float b[m];

        for (int i = 0; i < m; i++){
            for (int j = 0; j< n; j++){
                file>>a[i][j];
            }
            file>>b[i];
        }

    int nol[n];
    bool penyelesaian = true;
    float pengurang;
    float temp;

    for (int i = 0; i < m; i++){
        for (int j = 0 ;j < m;j++){
            nol[j] = 0;
        }
        for(int j = 0; j < m; j ++){
            bool eselon = true;
            for(int z = 0; z< n; z++){
                if (eselon && a[j][z] == 0){
                    nol[j]++;
                }else {
                    eselon = false;
                }
            }
            if(nol[j] == n){
                penyelesaian = false;
                break;
            }
        }
        for (int j = 0; j < m-1; j++){
           for (int z= j+1; z < n;z++)
                if(nol[j]>nol[z]){
                temp = nol[j];
                nol[j] = nol[z];
                nol[z] = temp;


                temp = b[j];
                b[j] = b[z];
                b[z] = b[j];

                for (int l = 0; l < n;l++){
                temp = a[j][l];
                a[j][l] = a[z][l];
                a[z][l] = temp;

           }

        }
        }

        //reduksi dari atas
        for (int j = 0; j < m; j++){
            bool mines = false;
                if(nol[i] == nol[j] && j > i){
                 for (int z = 0; z < n ;z++){
                    //untuk mencari perkalian yang ada seperti r1 + xr2 mencari nilai x konstanta patokan dari i
                    if(z == nol[i]){
                    pengurang = a[j][z]/ a[i][z];
                        if (pengurang < 0){
                            pengurang = pengurang * -1;
                        }

                        if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0 ){
                        mines = true;
                            b[j] = b[j] + (pengurang * b[i]);
                        }
                        else{
                            mines = false;
                            b[j] = b[j] - (pengurang * b[i]);
                        }

                    }
                    //sampe sini nyari konstanta

                    //ini untuk mpengurangan apakah di tambah atau dikurang agar nol jika + - maka ditambah jika ++ atau -- maka dikurang
                    if (mines){
                        a[j][z] = a[j][z] + pengurang * a[i][z];
                    }
                    else{
                         a[j][z] = a[j][z] - pengurang * a[i][z];
                    }

                }
                    //untuk invernsya di bagi karena ini mulai dari nol
            }
        }

      if(penyelesaian){
        //membuat eselon tereduksi
      float makeone;
          for (int j = 0; j < n; j++){
                if(i == j && i != 0 ){
                    if(a[i][j] != 1 && a[i][j] != 0){
                      makeone = 1 / a[i][j];
                      for (int z = 0; z < n; z++){
                        a[j][z] = a[j][z] * makeone;

                    }b[j] = b[j] * makeone;

                 }
             }

        }
        }

        //end

}
    if(penyelesaian){
    for (int i = m-1; i > 0; i--){
           for (int j = 0; j < i; j++){
                bool mines = false;
                   for(int z = 0; z < n; z++){
                        if(z == nol[i]){
                            pengurang = a[j][z]/ a[i][z];

                            if (pengurang < 0){
                                pengurang = pengurang * -1;
                            }
                            if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0 ){
                            mines = true;
                             b[j] = b[j] + (pengurang * b[i]);
                            }
                            else{
                            mines = false;
                             b[j] = b[j] - (pengurang * b[i]);
                            }

                        }
                        if (mines){
                            a[j][z] = a[j][z] + pengurang * a[i][z];
                        }
                        else{
                            a[j][z] = a[j][z] - pengurang * a[i][z];
                        }

                    }
                        //untuk invernsya di bagi karena ini mulai dari nol
                }

        }
        }
        cout<<endl;

        if (penyelesaian){
            for (int i =0 ;i < m; i++){
                if(isinf(b[i])||isnan(b[i])){
                    cout<<"Maaf tidak ada solusi di program ini"<<endl;
                    break;
                }
                cout<<"nilai dari x"<<i+1<<" = "<<b[i]<<endl;
            }
        }
        else{
            if(b[n-1] != 0){
            cout<<"Tidak ada penyelesaian";
            }
            else {
            cout<<"Solusi Banyak";
            }
        }
}
void SPLBalikan(){
    int n,m,temp;
    bool caninvers =  true;
    cout<<"Masukkan Banyaknya Baris (m)    = ";
    cin>>m;
    cout<<"Masukkan Banyaknya Variabel (n) = ";
    cin>>n;
    float a[m][n];
    float b[m];
    float invers[m][n];
    cout<<"Mengisi Matriks = " ;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin>>a[i][j];
            if (i == j){
                invers[i][j] = 1;
            }
            else
                invers[i][j] = 0;
        }
        cin>>b[i];
    }
    int nol[n];
    float pengurang;


    for (int i = 0; i < m; i++){
        for (int j = 0 ;j < m;j++){
            nol[j] = 0;
        }
        for(int j = 0; j < m; j ++){
            bool eselon = true;
            for(int z = 0; z< n; z++){
                if (eselon && a[j][z] == 0){
                    nol[j]++;
                }else {
                    eselon = false;
                }
            }
            if(nol[j] == n){
                caninvers = false;
                break;
            }
        }
        for (int j = 0; j < m-1; j++){
           for (int z= j+1; z <m;z++){
                if(nol[j]>nol[z]){
                    temp = nol[j];
                    nol[j] = nol[z];
                    nol[z] = temp;
                    for (int l = 0; l < n;l++){
                        temp = a[j][l];
                        a[j][l] = a[z][l];
                        a[z][l] = temp;
                    }
                }
            }
        }

        //reduksi dari atas
        for (int j = 0; j < m; j++){
            bool mines = false;
                if(nol[i] == nol[j] && j > i){
                 for (int z = 0; z < n ;z++){
                    //untuk mencari perkalian yang ada seperti r1 + xr2 mencari nilai x konstanta patokan dari i
                    if(z == nol[i]){
                    pengurang = a[j][z]/ a[i][z];
                        if (pengurang < 0){
                            pengurang = pengurang * -1;
                        }

                        if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0 ){
                        mines = true;
                        }
                        else{
                            mines = false;
                        }

                    }
                    //sampe sini nyari konstanta

                    //ini untuk mpengurangan apakah di tambah atau dikurang agar nol jika + - maka ditambah jika ++ atau -- maka dikurang
                    if (mines){
                        a[j][z] = a[j][z] + pengurang * a[i][z];
                        mines = true;
                    }
                    else{
                         a[j][z] = a[j][z] - pengurang * a[i][z];
                    }

                }
                    //untuk invernsya di bagi karena ini mulai dari nol
                    for (int z = 0; z < n; z++){
                     if (mines){
                        invers[j][z] = invers[j][z] + pengurang * invers[i][z];
                    }
                    else{
                         invers[j][z] = invers[j][z] - pengurang * invers[i][z];
                    }
                }
            }
        }

        //membuat eselon tereduksi
      float makeone;
          for (int j = 0; j < m; j++){
                if(i == j){
                    if(a[i][j] != 1){
                        makeone = 1 / a[i][j];
                        for (int z = 0; z < n; z++){
                            a[j][z] = a[j][z] * makeone;
                            invers[j][z] = invers[j][z] * makeone;
                        }

                    }
                }

            }

        //end

    }
    if (caninvers){
        for (int i = m-1; i > 0; i--){
           for (int j = 0; j < i; j++){
                bool mines = false;
                   for(int z = 0; z < n; z++){
                        if(z == nol[i]){
                            pengurang = a[j][z]/ a[i][z];

                            if (pengurang < 0){
                                pengurang = pengurang * -1;
                            }
                            if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0 ){
                            mines = true;
                        }
                        else{
                            mines = false;
                        }

                    }
                        if (mines){
                            a[j][z] = a[j][z] + pengurang * a[i][z];
                        }
                        else{
                            a[j][z] = a[j][z] - pengurang * a[i][z];
                        }

                    }
                        //untuk invernsya di bagi karena ini mulai dari nol
                        for (int z = 0; z < n; z++){
                        if (mines){
                            invers[j][z] = invers[j][z] + pengurang * invers[i][z];
                        }
                        else{
                            invers[j][z] = invers[j][z] - pengurang * invers[i][z];
                        }
                    }
                }

        }

        cout<<endl;
        cout<<"Maka Inversnya adalah = "<<endl;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cout<<invers[i][j]<<" ";
            }
            cout<<endl;
            cout<<endl;
        }
        float x[n-1];
           for (int i =0 ;i < n; i++){
            x[i]= 0;
        }

        float jumlah = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                for (int z =0 ;z < n; z++){
                    jumlah += invers[j][z] * b[z];
                }
                x[j] = jumlah;
                jumlah = 0;
            }
        }
          for (int i =0 ;i < n; i++){
            if(isinf(b[i])||isnan(b[i])){
                    cout<<"Maaf tidak ada solusi di program ini"<<endl;
                    break;
            }
            else
            cout<<"nilai dari x"<<i+1<<" = "<<x[i]<<endl;
        }

    }

    else {
         cout<<endl<<"Tidak Ada Solusi ";
    }
}
void SPLBalikanFile(){
    int n,m,temp;
    bool caninvers =  true;
    string inputfile;
    cout<<"Masukkan nama file = ";
    cin>>inputfile;
    fstream file;
    file.open(inputfile.c_str());
    file>>m;
    file>>n;
    float a[m][n];
    float b[m];
    float invers[m][n];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            file>>a[i][j];
            if (i == j){
                invers[i][j] = 1;
            }
            else
                invers[i][j] = 0;
        }
        file>>b[i];
    }
    int nol[n];
    float pengurang;


    for (int i = 0; i < m; i++){
        for (int j = 0 ;j < m;j++){
            nol[j] = 0;
        }
        for(int j = 0; j < m; j ++){
            bool eselon = true;
            for(int z = 0; z< n; z++){
                if (eselon && a[j][z] == 0){
                    nol[j]++;
                }else {
                    eselon = false;
                }
            }
            if(nol[j] == n){
                caninvers = false;
                break;
            }
        }
        for (int j = 0; j < m-1; j++){
           for (int z= j+1; z <m;z++){
                if(nol[j]>nol[z]){
                    temp = nol[j];
                    nol[j] = nol[z];
                    nol[z] = temp;
                    for (int l = 0; l < n;l++){
                        temp = a[j][l];
                        a[j][l] = a[z][l];
                        a[z][l] = temp;
                    }
                }
            }
        }

        //reduksi dari atas
        for (int j = 0; j < m; j++){
            bool mines = false;
                if(nol[i] == nol[j] && j > i){
                 for (int z = 0; z < n ;z++){
                    //untuk mencari perkalian yang ada seperti r1 + xr2 mencari nilai x konstanta patokan dari i
                    if(z == nol[i]){
                    pengurang = a[j][z]/ a[i][z];
                        if (pengurang < 0){
                            pengurang = pengurang * -1;
                        }

                        if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0 ){
                        mines = true;
                        }
                        else{
                            mines = false;
                        }

                    }
                    //sampe sini nyari konstanta

                    //ini untuk mpengurangan apakah di tambah atau dikurang agar nol jika + - maka ditambah jika ++ atau -- maka dikurang
                    if (mines){
                        a[j][z] = a[j][z] + pengurang * a[i][z];
                        mines = true;
                    }
                    else{
                         a[j][z] = a[j][z] - pengurang * a[i][z];
                    }

                }
                    //untuk invernsya di bagi karena ini mulai dari nol
                    for (int z = 0; z < n; z++){
                     if (mines){
                        invers[j][z] = invers[j][z] + pengurang * invers[i][z];
                    }
                    else{
                         invers[j][z] = invers[j][z] - pengurang * invers[i][z];
                    }
                }
            }
        }

        //membuat eselon tereduksi
      float makeone;
          for (int j = 0; j < m; j++){
                if(i == j){
                    if(a[i][j] != 1){
                        makeone = 1 / a[i][j];
                        for (int z = 0; z < n; z++){
                            a[j][z] = a[j][z] * makeone;
                            invers[j][z] = invers[j][z] * makeone;
                        }

                    }
                }

            }

        //end

    }
    if (caninvers){
        for (int i = m-1; i > 0; i--){
           for (int j = 0; j < i; j++){
                bool mines = false;
                   for(int z = 0; z < n; z++){
                        if(z == nol[i]){
                            pengurang = a[j][z]/ a[i][z];

                            if (pengurang < 0){
                                pengurang = pengurang * -1;
                            }
                            if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0 ){
                            mines = true;
                        }
                        else{
                            mines = false;
                        }

                    }
                        if (mines){
                            a[j][z] = a[j][z] + pengurang * a[i][z];
                        }
                        else{
                            a[j][z] = a[j][z] - pengurang * a[i][z];
                        }

                    }
                        //untuk invernsya di bagi karena ini mulai dari nol
                        for (int z = 0; z < n; z++){
                        if (mines){
                            invers[j][z] = invers[j][z] + pengurang * invers[i][z];
                        }
                        else{
                            invers[j][z] = invers[j][z] - pengurang * invers[i][z];
                        }
                    }
                }

        }

        cout<<endl;
        cout<<"Maka Inversnya adalah = "<<endl;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cout<<invers[i][j]<<" ";
            }
            cout<<endl;
            cout<<endl;
        }
        float x[n-1];
           for (int i =0 ;i < n; i++){
            x[i]= 0;
        }

        float jumlah = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                for (int z =0 ;z < n; z++){
                    jumlah += invers[j][z] * b[z];
                }
                x[j] = jumlah;
                jumlah = 0;
            }
        }
          for (int i =0 ;i < n; i++){
             if(isinf(b[i])||isnan(b[i])){
                    cout<<"Maaf tidak ada solusi di program ini"<<endl;
                    break;
            }
            else
                cout<<"nilai dari x"<<i+1<<" = "<<x[i]<<endl;
        }

    }

    else {
         cout<<endl<<"Tidak Ada Solusi ";
    }
}

float a[100][100];


float determinankofaktor(float a[ ][100], int n){
    float hasil = 0;
    int letak = 1;
    float temp[100][100];
    if(n == 1){
        return a[0][0];
    }
    else{
        for (int i = 0 ; i < n;i++){
            int det1 = 0, det2 = 0;
            for (int j = 0;j < n;j++){
                for (int z = 0; z < n;z++){
                    if(j != 0 && i != z){
                        temp[det1][det2] = a[j][z];
                        det2++;
                        if (det2 == n-1){
                            det1++;
                            det2 = 0;
                        }
                    }
                }
            }
            hasil += letak * a[0][i]* determinankofaktor(temp, n - 1);
            letak = letak * -1;
        }
        return hasil;
    }
}

void krammer(){
    int n,m;
    cout<<"Masukkan baris (m) = ";
    cin>>m;
    cout<<"Masukkan kolom (n) = ";
    cin>>n;
    if(m == n){
        cout<<"Mengisi Matriks = "<<endl;
        float b[n];
        float det[n];
        float detawal;
        float temp;
        bool solusi = true;
        for (int i =0 ;i < n;i++){
            for(int j =0 ;j < n;j++){
                cin>>a[i][j];
            }
            cin>>b[i];
        }
        detawal = determinankofaktor(a,n);
        for (int i =0 ;i < n; i++){
            for(int j = 0; j < n;j++){
                temp = a[j][i];
                a[j][i] = b[j];
                b[j] = temp;
            }
            det[i] = determinankofaktor(a,n);
            for(int j = 0; j < n;j++){
                temp = a[j][i];
                a[j][i] = b[j];
                b[j] = temp;
            }cout<<endl;
        }
        for (int i =0 ;i < n; i++){
            if(detawal == 0){
                solusi = false;
            }
        }
        if(solusi){
            for (int i =0 ;i < n;i++){
            cout<<"x"<<i+1<<" = "<<det[i]/detawal<<endl;
            }
        }
        else{
            cout<<"SPL Tidak ada penyelesaian"<<endl;
        }
    }else{
        cout<<endl<<"Jika baris tidak sama dengan kolom tidak dapat dieksekusi"<<endl;
    }
}

void krammerFile(){
    int n,m;
    string inputfile;
    cout<<"Masukkan nama file = ";
    cin>>inputfile;
    fstream file;
    file.open(inputfile.c_str());
    file>>m;
    file>>n;
    if (m == n){
        float b[n];
        float det[n];
        float detawal;
        float temp;
        bool solusi = true;

        for (int i =0 ;i < n;i++){
            for(int j =0 ;j < n;j++){
                file>>a[i][j];
            }
        file>>b[i];
        }

        detawal = determinankofaktor(a,n);

        for (int i =0 ;i < n; i++){
            for(int j = 0; j < n;j++){
                temp = a[j][i];
                a[j][i] = b[j];
                b[j] = temp;
            }

            det[i] = determinankofaktor(a,n);

            for(int j = 0; j < n;j++){
                temp = a[j][i];
                a[j][i] = b[j];
                b[j] = temp;
            }cout<<endl;
        }

        for (int i =0 ;i < n; i++){
            if(detawal == 0){
                solusi = false;
            }
        }
        if(solusi){
            for (int i =0 ;i < n;i++){
                cout<<"x"<<i+1<<" = "<<det[i]/detawal<<endl;
            }
        }
        else{
            cout<<"SPL Tidak ada penyelesaian"<<endl;
        }
    }
    else{
        cout<<endl<<"Jika kolomg dan baris tidak sama maka program tidak bisa jalan";
    }
}

//
//--inputSPL

//proses menu 2 = Determinan
void Reduksi_Baris(){
    int n;
    float temp;
    cout<<"Masukkan besar matriks (n x n) = ";
    cin>>n;
    float a[n][n];
    cout<<"Isi Matriks = "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }
    int nol[n];
    float pengurang;
    int tuker = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0 ;j < n;j++){
            nol[j] = 0;
        }
        for(int j = 0; j < n; j ++){
            bool eselon = true;
            for(int z = 0; z< n; z++){
                if (eselon && a[j][z] == 0){
                    nol[j]++;
                }else {
                    eselon = false;
                }
            }
        }
        for (int j = 0; j < n-1; j++){
           for (int z= j+1; z < n;z++)
                if(nol[j]>nol[z]){
                tuker++;
                temp = nol[j];
                nol[j] = nol[z];
                nol[z] = temp;

                for (int l = 0; l < n;l++){

                temp = a[j][l];
                a[j][l] = a[z][l];
                a[z][l] = temp;

                }
            }
         }
        bool ditambah = true;
        for (int j = 0; j < n; j++){
                if(nol[i] == nol[j] && j > i){
                 for (int z = 0; z < n ;z++){
                    if(z == nol[i]){
                    pengurang = a[j][z]/ a[i][z];
                        if (pengurang < 0){
                            pengurang = pengurang * -1;
                        }
                     if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0){
                        ditambah = false;
                     }
                     else
                        ditambah = true;
                    }
                    if (ditambah){
                        a[j][z] = a[j][z] - (pengurang * a[i][z]);
                    }
                    else{
                         a[j][z] = a[j][z] + (pengurang * a[i][z]);
                    }

                }
            }
        }

    }
    float determinan = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j)
            determinan = determinan * a[i][j];
        }
   }
   if (tuker % 2 == 1){
     determinan = determinan * -1;
   }cout<<endl;
   cout<<"Maka determinan matriks adalah = "<<determinan<<endl;
}


void Reduksi_Barisfile(){
    int n;
    float temp;
    int choose;
    string inputfile;
    cout<<"Masukkan nama file = ";
    cin>>inputfile;
    fstream file;
    file.open(inputfile.c_str());
    file >> n;
    float a[n][n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n;j++){
            file >>a[i][j];
        }
    }

    int nol[n];
    float pengurang;
    int tuker = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0 ;j < n;j++){
            nol[j] = 0;
        }
        for(int j = 0; j < n; j ++){
            bool eselon = true;
            for(int z = 0; z< n; z++){
                if (eselon && a[j][z] == 0){
                    nol[j]++;
                }else {
                    eselon = false;
                }
            }
        }
        for (int j = 0; j < n-1; j++){
           for (int z= j+1; z < n;z++)
                if(nol[j]>nol[z]){
                tuker++;
                temp = nol[j];
                nol[j] = nol[z];
                nol[z] = temp;

                for (int l = 0; l < n;l++){

                temp = a[j][l];
                a[j][l] = a[z][l];
                a[z][l] = temp;

                }
            }
         }
        bool ditambah = true;
        for (int j = 0; j < n; j++){
                if(nol[i] == nol[j] && j > i){
                 for (int z = 0; z < n ;z++){
                    if(z == nol[i]){
                    pengurang = a[j][z]/ a[i][z];
                        if (pengurang < 0){
                            pengurang = pengurang * -1;
                        }
                     if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0){
                        ditambah = false;
                     }
                     else
                        ditambah = true;
                    }
                    if (ditambah){
                        a[j][z] = a[j][z] - (pengurang * a[i][z]);
                    }
                    else{
                         a[j][z] = a[j][z] + (pengurang * a[i][z]);
                    }

                }
            }
        }

    }
    float determinan = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j)
            determinan = determinan * a[i][j];
        }
   }
   if (tuker % 2 == 1){
     determinan = determinan * -1;
   }cout<<endl;
   cout<<"Maka determinan matriks adalah = "<<determinan<<endl;
}

void kofaktor(){
    int n;
    cout<<"Masukkan Banyaknya n = ";
    cin>>n;
    cout<<"Masukkan Matriks = "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }
    cout<<determinankofaktor(a,n);
}

void kofaktorfile(){
    int n;
    string inputfile;
    cout<<"Masukkan nama file = ";
    cin>>inputfile;
    fstream file;
    file.open(inputfile.c_str());
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            file>>a[i][j];
        }
    }
    file>>n;
    cout<<determinankofaktor(a,n);
}



// prosesinvers
void Invers(){
    int n,temp;
    bool caninvers =  true;
    cout<<"Masukkan besar matriks (n x n) = ";
    cin>>n;
    float a[n][n];
    float invers[n][n];
    cout<<"Masukkan Matriks = "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin>>a[i][j];
            if (i == j){
                invers[i][j] = 1;
            }
            else
                invers[i][j] = 0;
        }
    }
    int nol[n];
    float pengurang;


    for (int i = 0; i < n; i++){
        for (int j = 0 ;j < n;j++){
            nol[j] = 0;
        }
        for(int j = 0; j < n; j ++){
            bool eselon = true;
            for(int z = 0; z< n; z++){
                if (eselon && a[j][z] == 0){
                    nol[j]++;
                }else {
                    eselon = false;
                }
            }
            if(nol[j] == n){
                caninvers = false;
                break;
            }
        }
        for (int j = 0; j < n-1; j++){
           for (int z= j+1; z < n;z++)
                if(nol[j]>nol[z]){
                temp = nol[j];
                nol[j] = nol[z];
                nol[z] = temp;
                for (int l = 0; l < n;l++){
                temp = a[j][l];
                a[j][l] = a[z][l];
                a[z][l] = temp;

           }

        }
         }

        //reduksi dari atas
        for (int j = 0; j < n; j++){
            bool mines = false;
                if(nol[i] == nol[j] && j > i){
                 for (int z = 0; z < n ;z++){
                    //untuk mencari perkalian yang ada seperti r1 + xr2 mencari nilai x konstanta patokan dari i
                    if(z == nol[i]){
                    pengurang = a[j][z]/ a[i][z];
                        if (pengurang < 0){
                            pengurang = pengurang * -1;
                        }

                        if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0 ){
                        mines = true;
                        }
                        else{
                            mines = false;
                        }

                    }
                    //sampe sini nyari konstanta

                    //ini untuk mpengurangan apakah di tambah atau dikurang agar nol jika + - maka ditambah jika ++ atau -- maka dikurang
                    if (mines){
                        a[j][z] = a[j][z] + pengurang * a[i][z];
                        mines = true;
                    }
                    else{
                         a[j][z] = a[j][z] - pengurang * a[i][z];
                    }

                }
                    //untuk invernsya di bagi karena ini mulai dari nol
                    for (int z = 0; z < n; z++){
                     if (mines){
                        invers[j][z] = invers[j][z] + pengurang * invers[i][z];
                    }
                    else{
                         invers[j][z] = invers[j][z] - pengurang * invers[i][z];
                    }
                }
            }
        }

        //membuat eselon tereduksi
      float makeone;
          for (int j = 0; j < n; j++){
                if(i == j){
                    if(a[i][j] != 1){
                      makeone = 1 / a[i][j];
                      for (int z = 0; z < n; z++){
                        a[j][z] = a[j][z] * makeone;
                        invers[j][z] = invers[j][z] * makeone;
                    }

                 }
             }

        }

        //end

}
    if (caninvers){
        for (int i = n-1; i > 0; i--){
           for (int j = 0; j < i; j++){
                bool mines = false;
                   for(int z = 0; z < n; z++){
                        if(z == nol[i]){
                            pengurang = a[j][z]/ a[i][z];

                            if (pengurang < 0){
                                pengurang = pengurang * -1;
                            }
                            if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0 ){
                            mines = true;
                        }
                        else{
                            mines = false;
                        }

                    }
                        if (mines){
                            a[j][z] = a[j][z] + pengurang * a[i][z];
                        }
                        else{
                            a[j][z] = a[j][z] - pengurang * a[i][z];
                        }

                    }
                        //untuk invernsya di bagi karena ini mulai dari nol
                        for (int z = 0; z < n; z++){
                        if (mines){
                            invers[j][z] = invers[j][z] + pengurang * invers[i][z];
                        }
                        else{
                            invers[j][z] = invers[j][z] - pengurang * invers[i][z];
                        }
                    }
                }

        }

        cout<<endl;
        cout<<"Maka Inversnya adalah = "<<endl;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout<<invers[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    else {
        cout<<endl<<"Matrisk tersebut tidak ada inversnya";
    }
}
//
void Inversfile(){
    int n,temp;
    bool caninvers =  true;
    string inputfile;
    cout<<"Masukkan nama file = ";
    cin>>inputfile;
    fstream file;
    file.open(inputfile.c_str());
    file >> n;
    float a[n][n];
    float invers[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            file >>a[i][j];
            if (i == j){
                invers[i][j] = 1;
            }
            else
                invers[i][j] = 0;
        }
    }
    int nol[n];
    float pengurang;


    for (int i = 0; i < n; i++){
        for (int j = 0 ;j < n;j++){
            nol[j] = 0;
        }
        for(int j = 0; j < n; j ++){
            bool eselon = true;
            for(int z = 0; z< n; z++){
                if (eselon && a[j][z] == 0){
                    nol[j]++;
                }else {
                    eselon = false;
                }
            }
            if(nol[j] == n){
                caninvers = false;
                break;
            }
        }
        for (int j = 0; j < n-1; j++){
           for (int z= j+1; z < n;z++)
                if(nol[j]>nol[z]){
                temp = nol[j];
                nol[j] = nol[z];
                nol[z] = temp;
                for (int l = 0; l < n;l++){
                temp = a[j][l];
                a[j][l] = a[z][l];
                a[z][l] = temp;

           }

        }
         }

        //reduksi dari atas
        for (int j = 0; j < n; j++){
            bool mines = false;
                if(nol[i] == nol[j] && j > i){
                 for (int z = 0; z < n ;z++){
                    //untuk mencari perkalian yang ada seperti r1 + xr2 mencari nilai x konstanta patokan dari i
                    if(z == nol[i]){
                    pengurang = a[j][z]/ a[i][z];
                        if (pengurang < 0){
                            pengurang = pengurang * -1;
                        }

                        if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0 ){
                        mines = true;
                        }
                        else{
                            mines = false;
                        }

                    }
                    //sampe sini nyari konstanta

                    //ini untuk mpengurangan apakah di tambah atau dikurang agar nol jika + - maka ditambah jika ++ atau -- maka dikurang
                    if (mines){
                        a[j][z] = a[j][z] + pengurang * a[i][z];
                        mines = true;
                    }
                    else{
                         a[j][z] = a[j][z] - pengurang * a[i][z];
                    }

                }
                    //untuk invernsya di bagi karena ini mulai dari nol
                    for (int z = 0; z < n; z++){
                     if (mines){
                        invers[j][z] = invers[j][z] + pengurang * invers[i][z];
                    }
                    else{
                         invers[j][z] = invers[j][z] - pengurang * invers[i][z];
                    }
                }
            }
        }

        //membuat eselon tereduksi
      float makeone;
          for (int j = 0; j < n; j++){
                if(i == j){
                    if(a[i][j] != 1){
                      makeone = 1 / a[i][j];
                      for (int z = 0; z < n; z++){
                        a[j][z] = a[j][z] * makeone;
                        invers[j][z] = invers[j][z] * makeone;
                    }

                 }
             }

        }

        //end

}
    if (caninvers){
        for (int i = n-1; i > 0; i--){
           for (int j = 0; j < i; j++){
                bool mines = false;
                   for(int z = 0; z < n; z++){
                        if(z == nol[i]){
                            pengurang = a[j][z]/ a[i][z];

                            if (pengurang < 0){
                                pengurang = pengurang * -1;
                            }
                            if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0 ){
                            mines = true;
                        }
                        else{
                            mines = false;
                        }

                    }
                        if (mines){
                            a[j][z] = a[j][z] + pengurang * a[i][z];
                        }
                        else{
                            a[j][z] = a[j][z] - pengurang * a[i][z];
                        }

                    }
                        //untuk invernsya di bagi karena ini mulai dari nol
                        for (int z = 0; z < n; z++){
                        if (mines){
                            invers[j][z] = invers[j][z] + pengurang * invers[i][z];
                        }
                        else{
                            invers[j][z] = invers[j][z] - pengurang * invers[i][z];
                        }
                    }
                }

        }

        cout<<endl;
        cout<<"Maka Inversnya adalah = "<<endl;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout<<invers[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    else {
        cout<<endl<<"Matrisk tersebut tidak ada inversnya";
    }
}


//--cara pilih inputan--
void carainput(){
    system("CLS");
    cout<<"1. Input konsol"<<endl;
    cout<<"2. Input File"<<endl;
    cout<<"Pilih cara input cara 1 atau 2 = ";
    cin>>pilihaninput;
    if (menunya == 1){
        if(pilihanSPl == 1){
            if (pilihaninput == 1)
                Gauss();
            else
                GaussFile();
        }
        else if(pilihanSPl == 2){
            if (pilihaninput == 1)
                Gauss_jordan();
            else
                Gauss_jordanFile();
        }
        else if(pilihanSPl == 3){
            if (pilihaninput == 1)
                SPLBalikan();
            else
                SPLBalikanFile();
        }
        else if (pilihanSPl == 4){
            if (pilihaninput == 1)
                krammer();
            else
                krammerFile();
        }
    }
    else if (menunya == 2){
        if(pilihandeterminan = 1){
         if (pilihaninput == 1)
            Reduksi_Baris();
        else
            Reduksi_Barisfile();
        }
        else if(pilihandeterminan = 2){
            if(pilihaninput == 1){
                kofaktor();
            }
            else {
                kofaktorfile();
            }
        }
    }
    else if (menunya == 3){
        if(pilihaninput == 1){
            Invers();
        }
        else {
            Inversfile();
        }
    }
}


//--menu Sistem Persamaan Linear--
void submenuSPL(){
    system("CLS");
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
    system("CLS");
    cout<<"1. Reduksi Baris"<<endl;
    cout<<"2. Ekspansi Kofaktor"<<endl;
    cout<<"Pilih menu (1-2) = ";
    cin>>pilihandeterminan;
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
