#include <iostream>
using namespace std;
struct node{
    int coff;
    int power;
    node *next;
    public:
    node(int n,int m){
        coff=n;
        power=m;
        next=NULL;
    }
};
class linkedlist{
    public:
    node *head;
    linkedlist(){
        head=NULL;
    }
    void insertend(int m, int n){
        node *newnode=new node(m,n);
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
    linkedlist add(linkedlist& other){
        linkedlist result;
        node *p1=head;
        node *p2=other.head;
        while(p1!=NULL && p2!=NULL){
            if(p1->power == p2->power){
                result.insertend(p1->coff + p2->coff, p1->power);
                p1=p1->next;
                p2=p2->next;
            }
            else if(p1->power > p2->power){
                result.insertend(p1->coff, p1->power);
                p1=p1->next;
            }
            else{
                result.insertend(p2->coff, p2->power);
                p2=p2->next;
            }
        }
        return result;
    }
};
int main(){
    linkedlist poly1;
    poly1.insertend(5,2);
    poly1.insertend(4,1);
    poly1.insertend(2,0);
    linkedlist poly2;
    poly2.insertend(5,1);
    poly2.insertend(5,0);
    linkedlist result = poly1.add(poly2);
    node *temp=result.head;
    while(temp!=NULL){
        cout<<temp->coff<<","<<temp->power<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}