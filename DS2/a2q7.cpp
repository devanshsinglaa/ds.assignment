#include <iostream>
using namespace std;
void input(int a[100], int n){
    
    cout<<"enter elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
int count(int a[100], int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                count++;
            }
        }
    }
    return count;
}
int main(){
    int arr[100];
    int n;
    cout<<"enter no of elements"<<endl;
    cin>>n;
    input(arr,n);
    int inversions=count(arr,n);
    cout<<"total inversions in array: "<<inversions;
    return 0;
}