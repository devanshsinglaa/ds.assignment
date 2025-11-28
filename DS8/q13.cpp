#include <iostream>
using namespace std;
struct node{
    int num;
    node *left, *right;
    node(int n): num(n), left(NULL), right(NULL) {}
};
struct dnode{
    int num;
    dnode *next,*prev;
    dnode(int n): num(n), next(NULL), prev(NULL) {}
};
class bst{
    public:
    node *root;
    bst(): root(NULL) {}
    node *insert(node *curr, int n){
        if(curr==NULL){return new node(n);}
        if(curr->num>n){
            curr->left=insert(curr->left,n);
        }else{
            curr->right=insert(curr->right,n);
        }
        return curr;
    }
    void inorder(node *curr, int a[], int &index){
        if(curr==NULL) return;
        inorder(curr->left,a,index);
        a[index++]=curr->num;
        inorder(curr->right,a,index);
    }
};
class dll{
    public:
    dnode *head, *tail;
    dll(): head(NULL), tail(NULL){}
    void insertend(int x){
        dnode *newnode=new dnode(x);
        if(head==NULL){head=tail=newnode;}
        dnode *temp=head;
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    void print(){
        dnode *curr=head;
        while(curr!=NULL){
            cout<<curr->num<<" ";
            curr=curr->next;
        }
    }
};
void merging(int a1[], int n1, int a2[], int n2, int merged[], int &m){
    int i=0,j=0;
    while(i<n1 &&j<n2){
        if(a1[i]<a2[j]){
            merged[m++]=a1[i++];
        }else{
            merged[m++]=a2[j++];
        }
    }
    while(i<n1) merged[m++] = a1[i++];
    while(j<n2) merged[m++] = a2[j++];
}
int main(){
    bst t1,t2;
    int a1[100], a2[100], merged[200],n1=0,n2=0,n3=0;
    t1.root=t1.insert(t1.root,5);
    t1.root=t1.insert(t1.root,3);
    t1.root=t1.insert(t1.root,7);

    t2.root=t2.insert(t2.root,4);
    t2.root=t2.insert(t2.root,2);
    t2.root=t2.insert(t2.root,6);

    t1.inorder(t1.root,a1,n1);
    t2.inorder(t2.root,a2,n2);
    merging(a1,n1,a2,n2,merged,n3);
    dll list;
    for(int i=0;i<n3;i++){
        list.insertend(merged[i]);
    }
    list.print();
    return 0;
}