#include <iostream>
using namespace std;
void input(int a[100], int n){
    
    cout<<"enter elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
void swap(int &a, int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void dutchflag(int a[100], int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(a[mid]==0){
            swap(a[low],a[mid]);
            mid++;
            low++;
            
        }else if(a[mid]==1){
            mid++;
            
        }else if(a[mid]==2){
            swap(a[high],a[mid]);
            high--;
        }
    }
}
int main(){
    int arr[100];
    int n;
    cout<<"enter no of elements";
    cin>>n;
    input(arr,n);
    cout<<"sorted array: ";
    dutchflag(arr,n);
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
    return 0;
}