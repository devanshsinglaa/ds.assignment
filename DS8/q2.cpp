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
    node* searchnon(int key){
        node *curr=root;
        while(curr!=NULL){
            if(curr->num==key){return curr;}
            else if(curr->num>key){curr=curr->left;}
            else{curr=curr->right;}
        }
        return NULL;
    }
    node* searchrec(node *curr, int key){
        if(curr->num==key){return curr;}
        if(curr->num>key){
            return searchrec(curr->left, key);
        }else{
            return searchrec(curr->right, key);
        }
    }
    node* minimum(node *curr){
        if(curr==NULL){return NULL;}
        while(curr->left!=NULL){
            curr=curr->left;
        }
        return curr;
    }
    node* maximum(node *curr){
        if(curr==NULL){return NULL;}
        while(curr->right!=NULL){
            curr=curr->right;
        }
        return curr;
    }
    node* inordersuccessor(node *root, node *key){
        if(key->right!=NULL){
            return minimum(key->right);
        }
        node *curr=root;
        node *succ=NULL;
        while(curr!=NULL){
            if(key->num<curr->num){
                succ=curr;
                curr=curr->left;
            }else if(key->num<curr->num){
                curr=curr->right;
            }
        }
        return succ;
    }
    node* inorderpredecessor(node *root, node *key){
        if(key->left!=NULL){
            return maximum(key->left);
        }
        node *curr=root;
        node *pred=NULL;
        while(curr!=NULL){
            if(key->num>curr->num){
                pred=curr;
                curr=curr->right;
            }else if(key->num<curr->num){
                curr=curr->left;
            }
        }
        return pred;
    }
};
int main(){
    bst tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    node *res=tree.searchnon(4);
    if(res!=NULL){
        cout<<"Found: "<<res->num<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
    res=tree.searchrec(tree.root, 6);
    if(res!=NULL){
        cout<<"Found: "<<res->num<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
    res=tree.minimum(tree.root);
    if(res!=NULL){
        cout<<"Minimum: "<<res->num<<endl;
    }
    res=tree.maximum(tree.root);
    if(res!=NULL){
        cout<<"Maximum: "<<res->num<<endl;}
    res=tree.inordersuccessor(tree.root, tree.root->left);
    if(res!=NULL){
        cout<<"Inorder Successor of "<<tree.root->left->num<<": "<<res->num<<endl;
    }
    res=tree.inorderpredecessor(tree.root, tree.root->right);
    if(res!=NULL){
        cout<<"Inorder Predecessor of "<<tree.root->right->num<<": "<<res->num<<endl;
    }
    return 0;
}