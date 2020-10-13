#include<iostream>
#include<stdlib.h>
#include <fstream>
using namespace std;

//reduksi Baris
//--main--
int main(){
    int n,temp;
    cin>>n;
    float a[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin>>a[i][j];
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

        for (int j = 0; j < n; j++){
                if(nol[i] == nol[j] && j > i){
                 for (int z = 0; z < n ;z++){
                    if(z == nol[i]){
                    pengurang = a[j][z]/ a[i][z];
                        if (pengurang < 0){
                            pengurang = pengurang * -1;
                        }
                    }
                    if (a[j][z] > 0 && a[i][z] < 0 ||a[j][z] < 0 && a[i][z] > 0  ){
                        a[j][z] = a[j][z] + pengurang * a[i][z];
                    }
                    else{
                         a[j][z] = a[j][z] - pengurang * a[i][z];
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
   cout<<"Maka determinan matriks adalah = "<<determinan;
}
