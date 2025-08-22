#include <iostream>
using namespace std;
int main(){
    int a[10][10];
    int m,n,temp;
    cout<<"enter no of rows and columns: ";
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        cin>>a[i][j];
        }
    }