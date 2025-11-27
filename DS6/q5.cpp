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
    bool iscircular(){
        if(head==NULL){
            return false;
        }
        node *temp=head->next;
        while(temp!=NULL && temp!=head){
            temp=temp->next;
        }
        if(temp==head){
            return true;
        }else {return false;}
    }
};
int main(){
    circularlist cl;
    cl.cinsertfirst(10);
    cl.cinsertfirst(20);
    cl.cinsertfirst(30);
    if(cl.iscircular()){
        cout<<" Is Circular Linked List";
    }
    else{
        cout<<"Not a Circular Linked List";
    }
    return 0;
}