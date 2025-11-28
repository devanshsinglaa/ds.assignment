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
    int prev;
    bool first;
    bst(){ 
        root=NULL;; 
        first=true;
        prev=-1;
    }
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
    bool checktree(node *curr, int prev, bool first){
        if(curr==NULL){return true;}
        if(!checktree(curr->left, prev, first)){return false;}
        if(!first && curr->num<=prev){return false;}
        first=false;
        prev=curr->num;
        return checktree(curr->right, prev, first);
    }
};
int main(){
    bst tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    if(tree.checktree(tree.root, tree.prev, tree.first)){
        cout<<"This is a BST"<<endl;
    }else{
        cout<<"This is not a BST"<<endl;
    }
    return 0;
}