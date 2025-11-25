#include <iostream>
using namespace std;
int getMax(int a[], int n){
    int mx = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > mx){
            mx = a[i];
        }
    }
    return mx;
}
void countSort(int a[], int n, int exp){
    int out[100];
    int c[10];
    for(int i = 0; i < 10; i++){
        c[i] = 0;
    }

    for(int i = 0; i < n; i++){
        int idx = (a[i] / exp) % 10;
        c[idx]++;
    }

    for(int i = 1; i < 10; i++){
        c[i] = c[i] + c[i - 1];
    }

    for(int i = n - 1; i >= 0; i--){
        int idx = (a[i] / exp) % 10;
        out[c[idx] - 1] = a[i];
        c[idx]--;
    }

    for(int i = 0; i < n; i++){
        a[i] = out[i];
    }
}
void radixSort(int a[], int n){
    int mx = getMax(a, n);
    for(int exp = 1; mx / exp > 0; exp *= 10){
        countSort(a, n, exp);
    }
}
int main(){
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    radixSort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
