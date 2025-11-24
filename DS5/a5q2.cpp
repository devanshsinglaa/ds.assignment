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
        else{
            node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    void countanddelete(int key){
        int count=0;
        while(head!=NULL &&head->num==key){
            node *temp=head;
            head=head->next;
            delete temp;
            count++;
        }
        node *temp=head;
        while(temp->next!=NULL){
            if(temp->next->num==key){
                node *del=temp->next;
                temp->next=temp->next->next;
                delete del;
                count++;
            }else{temp=temp->next;}
        }
        cout<<"count: "<<count<<endl;
        cout<<"modified list: ";
        display();
    }
    void display(){
        node *temp=head;
        while(temp!=NULL){
            cout<<" "<<temp->num;
            temp=temp->next;
        }
    }
};
int main(){
    linkedlist l;
    int key;
    cout<<"Enter key to be deleted: ";
    cin>>key;
    l.insertend(1);
    l.insertend(2);
    l.insertend(1);
    l.insertend(2);
    l.insertend(1);
    l.insertend(3);
    l.insertend(1);
    l.countanddelete(key);
    return 0;
}