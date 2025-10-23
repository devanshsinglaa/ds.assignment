#include <iostream>
#include <math.h>
using namespace std;
void input(int a[100], int n){
    
    cout<<"enter elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
int count(int a[100], int n, int k){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(abs(a[i]-a[j])==k){
                count++;
            }
        }
    }
    return count;
}
int main(){
    int arr[100];
    int n,k;
    cout<<"enter no of elements"<<endl;
    cin>>n;
    input(arr,n);
    cout<<"enter value of k";
    cin>>k;
    int noofpairs=count(arr,n,k);
    cout<<"total number of pairs with difference "<<k<<":"<<noofpairs<<endl;
    return 0;
}