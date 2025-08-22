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
   for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        cout<<" "<<a[i][j];
        }
        cout<<endl;
    }

    for(int i=0;i<m;i++){
        int rowsum=0;
        cout<<"sum of row "<<i<<": ";
        for(int j=0;j<n;j++){
            rowsum+=a[i][j];
        }
        cout<<rowsum<<endl;
    }

    for(int i=0;i<n;i++){
        int columnsum=0;
        cout<<"sum of column "<<i<<": ";
        for(int j=0;j<m;j++){
            columnsum+=a[j][i];
        }
        cout<<columnsum<<endl;
    }
    return 0;
}