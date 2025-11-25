#include <iostream>
using namespace std;
void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[m]) m=j;
        }
        int t=a[i];
        a[i]=a[m];
        a[m]=t;
    }
}
void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int x=a[i], j=i-1;
        while(j>=0 && a[j]>x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}
void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
void merge(int a[], int l, int m, int r){
    int n1=m-l+1, n2=r-m;
    int L[100], R[100];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}
void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int partition(int a[], int l, int r){
    int p=a[r], i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<p){
            i++;
            int t=a[i]; a[i]=a[j]; a[j]=t;
        }
    }
    int t=a[i+1]; a[i+1]=a[r]; a[r]=t;
    return i+1;
}
void quickSort(int a[], int l, int r){
    if(l<r){
        int p=partition(a,l,r);
        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}
void printArr(int a[], int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int a[100], b[100], c[100], d[100], e[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=c[i]=d[i]=e[i]=a[i];
    }

    selectionSort(a,n);
    printArr(a,n);

    insertionSort(b,n);
    printArr(b,n);

    bubbleSort(c,n);
    printArr(c,n);

    mergeSort(d,0,n-1);
    printArr(d,n);

    quickSort(e,0,n-1);
    printArr(e,n);

    return 0;
}