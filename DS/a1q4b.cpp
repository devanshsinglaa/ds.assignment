#include <iostream>
using namespace std;
int main(){
    int a[10][10], b[10][10], c[10][10];
    int m,n,o,p;
    cout<<"enter no of rows and columns of matrix 1: ";
    cin>>m>>n;
    cout<<"enter no of rows and columns of matrix 2: ";
    cin>>o>>p;
    if(o!=n){
        cout<<"invalid input!";
        return 0;
    }

    cout<<"enter elements of matrix 1: ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"enter elements of matrix 2: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            cin>>b[i][j];
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            c[i][j] = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            for(int k=0;k<n;k++){
                c[i][j]+= a[i][k] * b[k][j];
            }
        }
    }
    cout<<"multiplicated matrix is: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            cout<<" "<<c[i][j];
        }
        cout<<endl;
    }
    return 0;
}