#include <iostream>
using namespace std;
struct dnode{
    int data;
    dnode *next;
    dnode *prev;
    dnode(int n){
        data=n;
        next=NULL;
        prev=NULL;
    }
};
class doublylist{
    public:
    dnode *dhead, *tail;
    doublylist(){
        dhead=tail=NULL;
    }
    void dinsertend(int x){
        dnode *newnode=new dnode(x);
        if(dhead==NULL){
        dhead=tail=newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    }
    void reversegroup(int k){
        dnode *curr=dhead;
        dnode *newhead=NULL;
        dnode *newtail=NULL;
        while(curr!=NULL){
            int count=0;
            dnode *grouphead=NULL;
            dnode *grouptail=NULL;
            while(curr!=NULL && count<k){
                dnode *nxt=curr->next;
                if(grouphead==NULL){
                    grouphead=grouptail=curr;
                    curr->next=NULL;
                    curr->prev=NULL;
                }else{
                    curr->next=grouphead;
                    grouphead->prev=curr;
                    curr->prev=NULL;
                    grouphead=curr;
                }
                curr=nxt;
                count++;
            }
            if(newhead==NULL){
                newhead=grouphead;
                newtail=grouptail;
            }else{
                newtail->next=grouphead;
                grouphead->prev=newtail;
                newtail=grouptail;
            }
        }
        dhead=newhead;
        tail=newtail;
    }
};
int main(){
    doublylist dl;
    dl.dinsertend('1');
    dl.dinsertend('2');
    dl.dinsertend('3');
    dl.dinsertend('4');
    dl.dinsertend('5');
    dl.dinsertend('6');
    int k=2;
    dl.reversegroup(k);
    dnode *temp=dl.dhead;
    cout<<"Doubly Linked List after reversing in groups of "<<k<<": ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}