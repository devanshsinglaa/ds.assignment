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
    void preorder(node *curr){
        if(curr==NULL) return;
        cout<<curr->num<<" ";
        preorder(curr->left);
        preorder(curr->right);
    }
    void inorder(node *curr){
        if(curr==NULL) return;
        inorder(curr->left);
        cout<<curr->num<<" ";
        inorder(curr->right);
    }
    void postorder(node *curr){
        if(curr==NULL) return;
        postorder(curr->left);
        postorder(curr->right);
        cout<<curr->num<<" ";
    }
};
int main(){
    bst tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    cout<<"Preorder Traversal: ";
    tree.preorder(tree.root);
    cout<<endl;
    cout<<"Inorder Traversal: ";
    tree.inorder(tree.root);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    tree.postorder(tree.root);
    cout<<endl;
    return 0;
}