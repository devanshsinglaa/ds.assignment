#include <iostream>
using namespace std;
struct node{
    int num;
    node *left;
    node *right;
    node(int n): num(n), left(NULL), right(NULL) {}
};
class bst{
    public:
    node *root;
    bst(): root(NULL) {}
    void insert(int n){
        node *newnode=new node(n);
        if(root==NULL){
            root=newnode;
            return;
        }
        node *curr=root;
        node *parent=NULL;
        while(curr!=NULL){
            parent=curr;
            if(curr->num>n){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
        }
        if(parent->num>n){
            parent->left=newnode;
        }
        else{
            parent->right=newnode;
        }
    }
    int sumofleftleaves(node *curr){
        if(curr==NULL){return 0;}
        int sum=0;
        if(curr->left!=NULL &&curr->left->left==NULL && curr->left->right==NULL){
            sum+=curr->left->num;
        }
        sum+=sumofleftleaves(curr->left);
        sum+=sumofleftleaves(curr->right);
        return sum;
    }
};
int main(){
    bst tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    int result=tree.sumofleftleaves(tree.root);
    cout<<"Sum of left leaves: "<<result<<endl;
    return 0;
}