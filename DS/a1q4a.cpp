#include <iostream>
using namespace std;
int main(){
    int a[10];
    int n,temp;
    cout<<"enter no of elements: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"reverse of array is: ";
    for(int i=0;i<n/2;i++){
        temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;
        
    }
    for(int i=0;i<n;i++){
        cout<<" "<<a[i];
    }
    return 0;
}