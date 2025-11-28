#include <iostream>
using namespace std;
void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l < n && a[l] > a[largest]) largest = l;
    if(r < n && a[r] > a[largest]) largest = r;
    if(largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heapsortInc(int a[], int n) {
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>=0;i--) {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
void heapifyMin(int a[], int n, int i) {
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]<a[smallest]) smallest=l;
    if(r<n && a[r]<a[smallest]) smallest=r;
    if(smallest!=i){
        swap(a[i],a[smallest]);
        heapifyMin(a,n,smallest);
    }
}
void heapsortDec(int a[], int n) {
    for(int i=n/2-1;i>=0;i--) heapifyMin(a,n,i);
    for(int i=n-1;i>=0;i--) {
        swap(a[0],a[i]);
        heapifyMin(a,i,0);
    }
}
int main() {
    int a[]={5,3,8,4,1,2};
    int n=6;

    heapsortInc(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    int b[]={5,3,8,4,1,2};
    heapsortDec(b,n);
    for(int i=0;i<n;i++) cout<<b[i]<<" ";
}