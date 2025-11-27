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
void cdelete(int key){
    node *temp=chead;
    if(temp==NULL) return;
    if(temp->num==key){
        if(temp->next==chead){
            delete temp;
            chead=NULL;
            return;
        }
        node *last=chead;
        while(last->next!=chead){
            last=last->next;
        }
        chead=chead->next;
        last->next=chead;
        delete temp;
        return;
    }
    node *prev=temp;
    temp=temp->next;
    while(temp!=chead){
        if(temp->num==key){
            prev->next=temp->next;
            delete temp;
            return;
        }
        prev=temp;
        temp=temp->next;
    }
}
void ddelete(int key){
    dnode *temp=dhead;
    if(temp==NULL) return;
    if(temp->num==key){
        dhead=dhead->next;
        if(dhead!=NULL) dhead->prev=NULL;
        delete temp;
        return;
    }
    while(temp!=NULL){
        if(temp->num==key){
            if(temp->next!=NULL){
                temp->next->prev=temp->prev;
            }
            if(temp->prev!=NULL){
                temp->prev->next=temp->next;
            }
            delete temp;
            return;
        }
        temp=temp->next;
    }
}
int main(){
    int listType,key;
    while(true){
        cin>>listType;
        if(listType==0) break;
        cin>>key;
        if(listType==1) cdelete(key);
        else ddelete(key);
    }
    return 0;
}