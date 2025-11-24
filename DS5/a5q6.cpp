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
    node *head;
    public:
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
    void reverse(int k){
        if(k<=1 || head==NULL) return;
        node *current=head;
        node *prevGroupEnd=NULL;
        node *newHead=NULL;
        while(current){
            node *groupStart=current;
            node *prev=NULL;
            int count=0;
            node *check=current;
            for(int i=0;i<k;i++){
                if(!check) break;
                check=check->next;
                count++;
            }
            if(count<k){
                if(prevGroupEnd) prevGroupEnd->next=current;
                break;
            }
            count=0;
            while(current && count<k){
                node *next=current->next;
                current->next=prev;
                prev=current;
                current=next;
                count++;
            }
            if(!newHead) newHead=prev;
            if(prevGroupEnd) prevGroupEnd->next=prev;
            prevGroupEnd=groupStart;
        }
        head=newHead;
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
    linkedlist list;
    list.insertend(1);
    list.insertend(2);
    list.insertend(3);
    list.insertend(4);
    list.insertend(5);
    list.insertend(6);
    list.insertend(7);
    int k;
    cout<<"Enter k: ";
    cin>>k;
    list.reverse(k);
    cout<<"Reversed list in groups of "<<k<<": ";
    list.display();
    return 0;
}
