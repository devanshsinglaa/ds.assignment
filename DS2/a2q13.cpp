#include <iostream>
using namespace std;
void input(int a[100], int n){
    
    cout<<"enter elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
void doubling(int a[100],int n){
    int count2 = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == 2){
            count2++;}
    }
    int i=n-1, j=n+count2-1;
    while (i >= 0) {
        if (a[i] == 2) {
            if (j < n) a[j] = 2; 
            if (j < n) a[j] = 2;
            j--;
        } else {
            if (j < n) a[j] = a[i];
            j--;
        }
        i--;
    }
}

int main(){
    int arr[100];
    int n;
    cout<<"enter no of elements";
    cin>>n;
    input(arr,n);
    cout<<"new array: ";
    doubling(arr,n);
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
    return 0;
}