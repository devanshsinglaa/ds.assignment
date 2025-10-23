#include <iostream>
using namespace std;
void input(int a[100], int n){
    
    cout<<"enter elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
int countDistinct(int a[100], int n){
    int j,count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j])
                break;
        }
        if (j == i)
            count++;
    }
    return count;
}
int main(){
    int arr[100];
    int n;
    cout<<"enter no of elements"<<endl;
    cin>>n;
    input(arr,n);
    int distinct=countDistinct(arr,n);
    cout<<"distinct numbers are: "<<distinct;
    return 0;
}