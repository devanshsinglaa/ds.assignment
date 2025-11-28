#include <iostream>
using namespace std;
struct node{
    int num;
    node *left, *right;
    node(int n): num(n), left(NULL), right(NULL) {}
};
class tree{
    public:
    int preindex;
    tree(){preindex=0;}
    int search(int inorder[], int start, int end, int value){
        for(int i=start;i<=end;i++){
            if(inorder[i]==value){return i;}
            else return -1;
        }
    }
    node *build(int preorder[], int inorder[], int start, int end){
        if(start>end){return NULL;}
        int curr=preorder[preindex++];
        node *newnode=new node(curr);
        if(start==end){return newnode;}
        int inorderindex=search(inorder, start, end, curr);
        newnode->left=build(preorder, inorder, start, inorderindex-1);
        newnode->right=build(preorder, inorder, inorderindex+1, end);
        return newnode;
    }
    void postorder(node *curr){
        if(curr==NULL) return;
        postorder(curr->left);
        postorder(curr->right);
        cout<<curr->num<<" ";
    }
};
int main(){
    int n, inorder[100], preorder[100];
    cout<<"enter number of nodes: ";
    cin>>n;
    cout<<"enter inorder traversal: ";
    for(int i=0;i<n;i++){cin>>inorder[i];}
    cout<<"enter preorder traversal: ";
    for(int i=0;i<n;i++){cin>>preorder[i];}
    tree t;
    t.preindex=0;
    node *root=t.build(preorder,inorder,0,n-1);
    cout<<"postorder traversal: ";
    t.postorder(root);
    return 0;
}