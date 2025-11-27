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
void displaycircular(){
    node *temp=head;
    if(head == NULL) return;
    do{
        cout<<temp->num<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<head->num;
}
};
int main(){
    circularlist cl;
    cl.cinsertfirst(10);
    cl.cinsertfirst(20);
    cl.cinsertfirst(30);
    cl.displaycircular();
    return 0;
}