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
struct dnode{
    int num;
    dnode *next;
    dnode *prev;
    public:
    dnode(int n){
        num=n;
        next=NULL;
        prev=NULL;
    }
};
node *chead=NULL;
dnode *dhead=NULL;
void cinsertfirst(int x){
    node *newnode= new node(x);
    if(chead == NULL){
        chead=newnode;
        newnode->next=chead;
        return;
    }
    node *temp=chead;
    while(temp->next!=chead){
        temp=temp->next;
    }
    newnode->next=chead;
    temp->next=newnode;
    chead=newnode;
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
void cinsertlast(int x){
    node *newnode= new node(x);
    node *temp=chead;
    while(temp->next!=chead){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=chead;
}
void dinsertlast(int x){
    dnode *newnode=new dnode(x);
    dnode *temp=dhead;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}
void cinsertafter(int x, int key){
    node *newnode=new node(x);
    node *temp=chead;
    while(temp->num!=key){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void dinsertafter(int x, int key){
    dnode *newnode=new dnode(x);
    dnode *temp=dhead;
    while(temp->num!=key){
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    if(temp->next!=NULL){
        temp->next->prev=newnode;
    }
    temp->next=newnode;
}
int main(){
    cinsertfirst(10);
    cinsertlast(20);
    cinsertafter(15,10);
    cout<<"Circular Singly Linked List: ";
    node *temp=chead;
    do{
        cout<<temp->num<<" ";
        temp=temp->next;
    }while(temp!=chead);
    cout<<endl;

    dinsertfirst(30);
    dinsertlast(50);
    dinsertafter(40,30);
    cout<<"Doubly Linked List: ";
    dnode *dtemp=dhead;
    while(dtemp!=NULL){
        cout<<dtemp->num<<" ";
        dtemp=dtemp->next;
    }
    cout<<endl;
    return 0;
}