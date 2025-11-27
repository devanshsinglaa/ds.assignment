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
bool csearch(int key){
    node *temp=chead;
    while(temp!=chead){
        if(temp->num==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
bool dsearch(int key){
    dnode *temp=dhead;
    while(temp!=NULL){
        if(temp->num==key){
            return true;
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
        if(listType==1) cout<<csearch(key)<<endl;
        else cout<<dsearch(key)<<endl;
    }
    return 0;
}