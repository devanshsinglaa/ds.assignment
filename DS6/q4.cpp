#include <iostream>
using namespace std;
struct dnode{
    char data;
    dnode *next;
    dnode *prev;
    dnode(char n){
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
    void dinsertfirst(char x){
        dnode *newnode=new dnode(x);
        if(dhead==NULL){
        dhead=tail=newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    }
    bool palindrome(){
        if(dhead==NULL){return false;}
        dnode *left=dhead;
        dnode *right=dhead;
        while(left!=right && right->next!=left){
            if(left->data!=right->data){
                return false;
            }
            right=right->prev;
            left=left->next;
        }
        return true;
    }
};
int main(){
    doublylist dl;
    dl.dinsertfirst('l');
    dl.dinsertfirst('e');
    dl.dinsertfirst('v');
    dl.dinsertfirst('e');
    dl.dinsertfirst('l');
    if(dl.palindrome()){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not a Palindrome";
    }
    return 0;
}