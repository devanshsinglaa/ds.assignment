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
    node *head;
    public:
    linkedlist(){
        head=NULL;
    }
    void insertend(int n){
        node *newnode=new node(n);
        if(head==NULL){
            head=newnode;
            return;
        }
        else{
            node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    void findmiddle(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        node *first=head;
        node *second=head;
        while(second!=NULL && second->next!=NULL){
            first=first->next;
            second=second->next->next;
        }
        cout<<"Middle element is: "<<first->num<<endl;
    }
};
int main(){
    linkedlist l;
    l.insertend(1);
    l.insertend(2);
    l.insertend(3);
    l.insertend(4);
    l.insertend(5);
    l.findmiddle();
    return 0;
}