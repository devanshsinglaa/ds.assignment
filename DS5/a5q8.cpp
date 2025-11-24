#include <iostream>
using namespace std;
struct node{
    int num;
    node *next;
    public:
    node(int n){
        num=n;
        next=NULL;
    }
};
class linkedlist{
    public:
    node *head;
    linkedlist(){
        head=NULL;
    }
    void insertend(int n){
        node *newnode=new node(n);
        if(head==NULL){
            head=newnode;
            return;
        }
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    node* rotateleft(int k){
        if(k==0||head==NULL) return head;
        node *temp=head;
        int len=1;
        while(temp->next!=NULL){
            temp=temp->next;
            len++;
        }
        temp->next=head;
        k=k%len;
        while(k--){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};
int main(){
    linkedlist l;
    l.insertend(1);
    l.insertend(2);
    l.insertend(3);
    l.insertend(4);
    l.insertend(5);
    int k;
    cout<<"Enter k: ";
    cin>>k;
    cout<<"head of new list: "<<l.rotateleft(k)->num<<endl;
    return 0;
}