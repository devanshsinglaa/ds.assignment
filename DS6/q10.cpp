#include<iostream>
using namespace std;
struct node{
    int num;
    node *next;
    node *prev;
    node *up;
    node *down;
    node(int n){
        num=n;
        next=prev=up=down=NULL;
    }
};
node *matrixtodll(int a[][100], int n){
    node *matrix[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=new node(a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j+1<n){
                matrix[i][j]->next=matrix[i][j+1];
                matrix[i][j+1]->prev=matrix[i][j];
            }
            if(i+1<n){
                matrix[i][j]->down=matrix[i+1][j];
                matrix[i+1][j]->up=matrix[i][j];
            }
        }
    }
    return matrix[0][0];
}
void printdll(node *head, int n){
    node *row=head;
    for(int i=0;i<n;i++){
        node *col=row;
        for(int j=0;j<n;j++){
            cout<<col->num<<" ";
            col=col->next;
        }
        cout<<endl;
        row=row->down;
    }
}
int main(){
    int n, a[100][100];
    cout<<"enter rows of square matrix: ";
    cin>>n;
    cout<<"enter elements: ";
    for(int i=-0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    node *head=matrixtodll(a,n);
    printdll(head,n);
    return 0;
}