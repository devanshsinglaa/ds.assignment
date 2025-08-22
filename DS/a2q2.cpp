#include <iostream>
using namespace std;
int main(){
    int a[7]= {64,34,25,12,22,11,90};
    int temp;
    for(int i=0;i<7;i++){
        for(int j=0;j<7-i-1;j++){
            if(a[j]>a[j+1]){
                temp= a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<"sorted array is: ";
    for(int i=0;i<7;i++){
        cout<<" "<<a[i];
    }
    return 0;
}