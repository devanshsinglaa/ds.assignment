#include <iostream>
using namespace std;
struct node{
    int num;
    node *left, *right;
    node(int n): num(n), left(NULL), right(NULL) {}
};
class tree{
    public:
    int postindex;
    tree(){postindex=0;}
    int search(int inorder[], int start, int end, int value){
        for(int i=start;i<=end;i++){
            if(inorder[i]==value){return i;}
            else return -1;
        }
    }
    node *build(int postorder[], int inorder[], int start, int end){
        if(start>end){return NULL;}
        node *root=new node(postorder[postindex++]);
        if(start==end){return root;}
        int mid=search(inorder,start,end,root->num);
        root->right=build(postorder,inorder,mid+1,end);
        root->left=build(postorder,inorder,start,mid-1);
        return root;
    }
    void preorder(node *curr){
        if(curr==NULL) return;
        cout<<curr->num<<" ";
        preorder(curr->left);
        preorder(curr->right);
    }
};
int main(){
    int n,inorder[100],postorder[100];
    cout<<"enter number of nodes: ";
    cin>>n;
    cout<<"enter inorder traversal: ";
    for(int i=0;i<n;i++){cin>>inorder[i];}
    cout<<"enter postorder traversal: ";
    for(int i=0;i<n;i++){cin>>postorder[i];}
    tree t;
    t.postindex=n-1;
    node *root=t.build(postorder,inorder,0,n-1);
    cout<<"preorder traversal: ";
    t.preorder(root);
    return 0;
}