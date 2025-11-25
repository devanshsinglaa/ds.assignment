#include <iostream>
using namespace std;
void countSort(int a[], int n){
    int mx = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > mx){
            mx = a[i];
        }
    }
    int c[mx + 1];
    for(int i = 0; i <= mx; i++){
        c[i] = 0;
    }

    for(int i = 0; i < n; i++){
        c[a[i]]++;
    }

    int k = 0;
    for(int i = 0; i <= mx; i++){
        while(c[i] > 0){
            a[k] = i;
            k++;
            c[i]--;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    countSort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
