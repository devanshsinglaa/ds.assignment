#include <iostream>
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
    int data;
    dnode *next;
    dnode *prev;
    dnode(char n){
        data=n;
        next=NULL;
        prev=NULL;
    }
};
bool parity(int x){
    int count=0;
    while(x>0){
        count+=(x&1);
        x>>=1;
    }
    if(count%2==0){return true;}else{return false;}
}
class doublylist{
    public:
    dnode *dhead, *tail;
    doublylist(){
        dhead=tail=NULL;
    }
    void dinsertfirst(int x){
        dnode *newnode=new dnode(x);
        if(dhead==NULL){
        dhead=tail=newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    }
    void removeparity(){
        dnode *temp=dhead;
        while(temp!=NULL){
            dnode *nxt=temp->next;
            if(parity(temp->data)){
                if(temp==dhead){
                    dhead=dhead->next;
                    if(dhead!=NULL){
                        dhead->prev=NULL;
                }
            }else{
                temp->prev->next=temp->next;
                if(temp->next!=NULL){
                    temp->next->prev=temp->prev;
                }
            }
            delete temp;
        }
        temp=nxt;
    }
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
    void removeparity(){
        if(head==NULL)return;
        while(head!=NULL && parity(head->num)){
            node *temp=head;
            while(temp->next!=head){temp=temp->next;}
            if(temp==head){
                delete head;
                head=NULL;
                return;
            }
            node *del=head;
            head=head->next;
            temp->next=head;
            delete del;
        }
        node *curr=head;
        while(curr->next!=head){
            if(parity(curr->next->num)){
                node *del=curr->next;
                curr->next=curr->next->next;
                delete del;
            }else{
                curr=curr->next;
            }
        }
    }
};
int main(){
    doublylist dl;
    dl.dinsertfirst('18');
    dl.dinsertfirst('15');
    dl.dinsertfirst('8');
    dl.dinsertfirst('9');
    dl.dinsertfirst('14');
    dl.removeparity();
    dnode *temp=dl.dhead;
    cout<<"Doubly Linked List after removing parity nodes: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    circularlist cl;
    cl.cinsertfirst(3);
    cl.cinsertfirst(5);
    cl.cinsertfirst(7);
    cl.cinsertfirst(9);
    cl.cinsertfirst(11);
    cl.removeparity();
    node *curr=cl.head;
    if(curr==NULL){
        cout<<"Circular Linked List after removing parity nodes is empty.";
    }else{
        cout<<"Circular Linked List after removing parity nodes: ";
        do{
            cout<<curr->num<<" ";
            curr=curr->next;
        }while(curr!=cl.head);
    }
    return 0;
}