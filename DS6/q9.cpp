#include <iostream>
using namespace std;
struct dnode{
    int data;
    dnode *next;
    dnode *prev;
    dnode *random;
    dnode(int n){
        data=n;
        next=prev=random=NULL;
    }
};
class doublylist{
    public:
    dnode *dhead, *tail, *random;
    doublylist(){
        dhead=tail=random=NULL;
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
    void fixrandom(){
        dnode *temp=dhead;
        while(temp!=NULL){
            dnode *expected=temp->next;
            if(temp->random!=expected){
                temp->random=expected;
            }
            temp=temp->next;
        }
    }
    void print(){
        dnode *temp=dhead;
        while(temp!=NULL){
            cout<<temp->data<<" -> Random: ";
            if (temp->random)
                cout << temp->random->data;
            else
                cout << "NULL";
            cout << endl;
            temp = temp->next;
        }
    }
};
int main(){
    doublylist dl;
    dl.dinsertend('1');
    dl.dinsertend('2');
    dl.dinsertend('3');
    dl.dinsertend('4');
    dl.dhead->next->random=dl.dhead;
    cout<<"before fixing: "<<endl;
    dl.print();
    cout<<"after fixing: "<<endl;
    dl.fixrandom();
    dl.print();
    return 0;
}