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
    void removeloop(){
        node *slow=head;
        node *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        if(slow==fast){
            while(slow->next!=fast){
                slow=slow->next;
            }
            fast->next=NULL;
        }
    }
    void display(){
        node *temp=head;
        while(temp!=NULL){
            cout<<" "<<temp->num;
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    linkedlist l;
    l.insertend(1);
    l.insertend(2);
    l.insertend(3);
    l.insertend(4);
    l.insertend(5);

    l.head->next->next->next->next->next=l.head->next;
    l.removeloop();
    l.display();
    return 0;
}