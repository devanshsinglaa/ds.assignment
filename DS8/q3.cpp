#include <iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node(int n): data(n), left(NULL), right(NULL) {}
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
            if(curr->data>n){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
        }
        if(parent->data>n){
            parent->left=newnode;
        }
        else{
            parent->right=newnode;
        }
    }
    void deletenode(int key){
          node *curr = root, *parent = NULL;
        while (curr != NULL && curr->data != key) {
            parent = curr;
            if (key < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (curr == NULL) {
            cout << "Value not found: " << key << endl;
            return;
        }
        if (curr->left != NULL && curr->right != NULL) {
            node *succ = curr->right;
            node *succParent = curr;

            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }
            curr->data = succ->data;

            curr = succ;
            parent = succParent;
        }
        node *child = (curr->left != NULL) ? curr->left : curr->right;

        if (parent == NULL) {
            root = child;
        }
        else if (parent->left == curr) {
            parent->left = child;
        }
        else {
            parent->right = child;
        }

        delete curr;
    }
    int maxdepth(node *curr){
        if(curr==NULL){return 0;}
        int leftD=maxdepth(curr->left);
        int rightD=maxdepth(curr->right);
        return max(leftD, rightD)+1;
    }
    int mindepth(node *curr){
        if(curr==NULL){return 0;}
        if(curr->left==NULL && curr->right==NULL){return 1;}
        if(curr->left==NULL){
            return 1+mindepth(curr->right);
        }
        if(curr->right==NULL){
            return 1+mindepth(curr->left);
        }
        int leftD=mindepth(curr->left);
        int rightD=mindepth(curr->right);
        return min(leftD, rightD)+1;
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
    cout<<"Max Depth: "<<tree.maxdepth(tree.root)<<endl;
    cout<<"Min Depth: "<<tree.mindepth(tree.root)<<endl;
    tree.deletenode(3);
    cout<<"After deleting 3, Max Depth: "<<tree.maxdepth(tree.root)<<endl;
    cout<<"After deleting 3, Min Depth: "<<tree.mindepth(tree.root)<<endl;
    return 0;
}