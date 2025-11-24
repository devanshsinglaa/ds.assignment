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
node *intersectionNode(node *head1, node *head2){
    node *temp=head1;
    node *temp2=head2;
    while(temp!=temp2){
        if(temp==NULL){
            temp=head2;
        }else{
            temp=temp->next;
        }
        if(temp2==NULL){
            temp2=head1;
        }else{
            temp2=temp2->next;
        }
    }
    return temp;
}
int main(){
    node *common=new node(8);
    common->next=new node(5);
    node *head1=new node(4);
    head1->next=new node(1);
    head1->next->next=common;
    node *head2=new node(5);
    head2->next=new node(6);
    head2->next->next=new node(1);
    head2->next->next->next=common;
    node *intersect=intersectionNode(head1,head2);
    if(intersect){
        cout<<"Intersection at node with value: "<<intersect->num<<endl;}
    return 0;
}