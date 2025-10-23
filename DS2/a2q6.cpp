#include <iostream>
using namespace std;
void input(int a[100][3]){
    cout<<"input number of rows columns and values: "<<endl;
    cin>>a[0][0]>>a[0][1]>>a[0][2];

    cout<<"enter alues: "<<endl;
    for(int i=0;i<a[0][2];i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
}
void display(int a[100][3]){
    cout<<"\nRow\tCol\tVal\n";
    for (int i = 0; i <= a[0][2]; i++) {
        cout << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << endl;
    }
}
void transpose(int a[100][3], int b[100][3]){
    b[0][0]=a[0][1];
    b[0][1]=a[0][0];
    b[0][2]=a[0][2];
    int k=1;
    for(int i=0;i<a[0][1];i++){
        for(int j=1;j<=a[0][2];j++){
            if(a[j][1]==i){
                b[k][0]=a[i][1];
                b[k][1]=a[i][0];
                b[k][2]=a[i][2];
                k++;
            }
        }
    }
}
void add(int a[100][3], int b[100][3], int sum[100][3]){
    int i=1,j=1,k=1;
    sum[0][0]=a[0][0];
    sum[0][1]=a[0][1];

    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2];
            i++; k++;
        } 
        else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            sum[k][0] = b[j][0];
            sum[k][1] = b[j][1];
            sum[k][2] = b[j][2];
            j++; k++;
        } 
        else {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        }
    }
    while (i <= a[0][2]) {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        i++; k++;
    }

    while (j <= b[0][2]) {
        sum[k][0] = b[j][0];
        sum[k][1] = b[j][1];
        sum[k][2] = b[j][2];
        j++; k++;
    }
}
void multiply(int a[100][3], int b[100][3], int result[100][3]){

    int bT[100][3];
    transpose(b, bT);

    result[0][0] = a[0][0];
    result[0][1] = b[0][1];
    int k = 1;

    for (int i = 0; i < a[0][0]; i++) {
        for (int j = 0; j < bT[0][0]; j++) {
            int sum = 0;
            for (int x = 1; x <= a[0][2]; x++) {
                if (a[x][0] != i) continue;
                for (int y = 1; y <= bT[0][2]; y++) {
                    if (bT[y][0] != j) continue;
                    if (a[x][1] == bT[y][1])
                        sum += a[x][2] * bT[y][2];
                }
            }
            if (sum != 0) {
                result[k][0] = i;
                result[k][1] = j;
                result[k][2] = sum;
                k++;
            }
        }
    }
    result[0][2] = k - 1;
}

int main(){
    int a[100][3], b[100][3], c[100][3];
    cout << "enter first sparse matrix:" <<endl;
    input(a);
    cout << "enter second sparse matrix:" <<endl;
    input(b);
    cout<<"addition of both"<<endl;
    add(a,b,c);
    display(c);
    cout<<"multiplication of both"<<endl;
    multiply(a,b,c);
    display(c);
    return 0;
}