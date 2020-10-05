#include<iostream>
#include<stdlib.h>
#include <fstream>
using namespace std;

//--menu Sistem Persamaan Linear cara Gauss--
//--main--
int main(){
      int m;
    int n;
    cin>>m>>n;
    float a[m][n];
    float b[m];
        for (int i = 0; i < m; i++){
            for (int j = 0; j< n; j++){
                cin>>a[i][j];
            }
            cin>>b[i];
        }
}
