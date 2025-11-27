#include<iostream>
using namespace std;
struct node{
    int num;
    node *next;
    node(int n){
        num=n;
        next=NULL;
    }
};
struct dnode{
    int num;
    dnode *next;
    dnode *prev;
    dnode(int n){
        num=n;
        next=NULL;
        prev=NULL;
    }
};
class doublylist{
    public:
    dnode *dhead;
    doublylist(){
        dhead=NULL;
    }
    void dinsertfirst(int x){
        dnode *newnode=new dnode(x);
        if(dhead==NULL){
        dhead=newnode;
        return;
    }
    newnode->next=dhead;
    dhead->prev=newnode;
    dhead=newnode;
    }
    int dsize(){
        int count=0;
        dnode *temp=dhead;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
};
class circularlist{
    public:
    node *head;
    circularlist(){
        head=NULL;
    }
    void cinsertfirst(int x){
    node *newnode= new node(x);
    if(head == NULL){
        head=newnode;
        newnode->next=head;
        return;
    }
    node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    newnode->next=head;
    temp->next=newnode;
    head=newnode;
    }
    int csize(){
        int count=0;
        node *temp=head;
        if(head==NULL) return 0;
        do{
            count++;
            temp=temp->next;
        }while(temp!=head);
        return count;
    }
};
int main(){
    circularlist cl;
    cl.cinsertfirst(10);
    cl.cinsertfirst(20);
    cl.cinsertfirst(30);
    doublylist dl;
    dl.dinsertfirst(15);
    dl.dinsertfirst(25);
    dl.dinsertfirst(35);
    cout<<"Circular List Size: "<<cl.csize()<<endl;
    cout<<"Doubly List Size: "<<dl.dsize()<<endl;
    return 0;
}