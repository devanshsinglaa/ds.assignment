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
    void split(circularlist &cl1, circularlist &cl2){
        if(head==NULL){
            return;
        }
        node *slow=head;
        node *fast=head;
        while(fast->next!=head && fast->next->next!=head){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next->next==head){
            fast=fast->next;
        }
        cl1.head=head;
        cl2.head=slow->next;
        slow->next=cl1.head;
        fast->next=cl2.head;
    }
};
int main(){
    circularlist cl;
    cl.cinsertfirst(10);
    cl.cinsertfirst(20);
    cl.cinsertfirst(30);
    cl.cinsertfirst(40);
    cl.cinsertfirst(50);
    circularlist cl1, cl2;
    cl.split(cl1, cl2);
    node *temp;
    cout<<"First Circular Linked List: ";
    temp=cl1.head;
    if(temp!=NULL){
        do{
            cout<<temp->num<<" ";
            temp=temp->next;
        }while(temp!=cl1.head);
    }
    cout<<endl;
    cout<<"Second Circular Linked List: ";
    temp=cl2.head;
    if(temp!=NULL){
        do{
            cout<<temp->num<<" ";
            temp=temp->next;
        }while(temp!=cl2.head);
    }
    return 0;
}