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
    void insertbeg(int n){
        node *newnode=new node(n);
        newnode->next=head;
        head=newnode;
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
    void insert(int n, int value){
        node *newnode=new node(n);
        node *temp=head;
        if(head==NULL){
            head=newnode;
            return;
        }
        while(temp!=NULL && temp->num!=value){
            temp=temp->next;
        }
        if(temp!=NULL){
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    void delbeg(){
        head=head->next;
    }
    void delend(){
       if(head->next==NULL){
            head=NULL;
            return;
       }else{
            node *temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            temp->next=NULL;
       }
    }
    void del(int value){
        if(head->num==value){
            head=head->next;
            return;
        }
        node *temp=head;
        while(temp->next!=NULL && temp->next->num!=value){
            temp=temp->next;
        }
        node *del=temp->next;
        temp->next=temp->next->next;
        delete del;
    }
    void search(int value){
        node *temp=head;
        int count=1;
        while(temp!=NULL){
            if(temp->num=value){
                cout<<"found at position "<<count<<endl;
                return;
            }
            temp=temp->next;
            count++;
        }
    }
    void display(){
        node *temp=head;
        cout<<"linked list: ";
        while(temp!=NULL){
            cout<<" "<<temp->num;
            temp=temp->next;
        }
    }
};
int main(){
    linkedlist list;
    int choice,n,value;
    while (true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a value\n";
        cout << "4. Insert after a value\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific value\n";
        cout << "8. Search a value\n";
        cout << "9. Display list\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout<<"Enter number to insert at beginning: ";
                cin>>n;
                list.insertbeg(n);
                break;
            case 2:
                cout<<"Enter number to insert at end: ";
                cin>>n;
                list.insertend(n);
                break;
            case 3:
                cout<<"Enter number to insert: ";
                cin>>n;
                cout<<"Enter value to insert before: ";
                cin>>value;
                list.insert(n, value);
                break;
            case 4:
                cout<<"Enter number to insert: ";
                cin>>n;
                cout<<"Enter value to insert after: ";
                cin>>value;
                list.insert(n, value);
                break;
            case 5:
                list.delbeg();
                break;
            case 6:
                list.delend();
                break;
            case 7:
                cout<<"Enter value to delete: ";
                cin>>value;
                list.del(value);
                break;
            case 8:
                cout<<"Enter value to search: ";
                cin>>value;
                list.search(value);
                break;
            case 9:
                list.display();
                break;
            case 10:
                return 0;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
}
    return 0;
}