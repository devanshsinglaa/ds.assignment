#include <iostream>
using namespace std;

void linearSearch(int a[], int n, int el){
    for(int i=0;i<n;i++){
        if(a[i]==el){
            cout<<" element found at index "<<i<<endl;
        }
    }
}

void binarySearch(int a[], int n, int el){
    int mid,lb,ub;
    lb=0;
    ub=n-1;
    for(;lb<=ub;){
        mid=(lb+ub)/2;
        if(a[mid]==el){
            cout<<" element found at index "<<mid<<endl;
            break;

        }else if(el>a[mid]){
            lb=mid+1;

        }else {
            ub=mid-1;
        }
    }
}

int main(){
    int n, a[10],el;
    cout<<"enter no of elements: ";
    cin>>n;
    cout<<"enter elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"element to search: ";
    cin>>el;
    cout<<"by linear search ";
    linearSearch(a, n, el);
    cout<<"by binary search ";
    binarySearch(a, n, el);
    return 0;
}