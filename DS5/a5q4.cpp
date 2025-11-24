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
    void reverse(){
        node *temp=NULL;
        node *temp2=NULL;
        while(head!=NULL){
            temp2=head->next;
            head->next=temp;
            temp=head;
            head=temp2;
        }
        head=temp;
    }
    void display(){
        node *temp=head;
        while(temp!=NULL){
            cout<<" "<<temp->num;
            temp=temp->next;
        }
    }
};
int main(){
    linkedlist l;
    l.insertend(1);
    l.insertend(2);
    l.insertend(3);
    l.insertend(4);
    l.insertend(5);
    l.reverse();
    cout<<"Reversed list: ";
    l.display();
    return 0;
}