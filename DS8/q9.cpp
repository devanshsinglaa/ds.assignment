#include <iostream>
using namespace std;
struct node{
    int num;
    node *left, *right;
    node(int n): num(n), left(NULL), right(NULL) {}
};
struct queue{
    node *a[100];
    int front,rear;
    queue(){front=0; rear=0;}
    void push(node *n){
        a[rear++]=n;
    }
    node* pop(){
        return a[front++];
    }
    bool empty(){
        return front==rear;
    }
    int size(){
        return rear-front;
    }
};
node *tree(int n, int arr[]){
    if(n==0||arr[0]==-1){return NULL;}
    node *nodes[100];
    for(int i=0;i<n;i++){
        if(arr[i]==-1){return NULL;}
        nodes[i]=new node(arr[i]);
    }
    for(int i=0;i<n;i++){
        if(2*i+1<n){
            nodes[i]->left=nodes[2*i+1];
        }
        if(2*i+2<n){
            nodes[i]->right=nodes[2*i+2];
        }
    }
    return nodes[0];
}
void rightView(node* root) {
    if(root == NULL) return;

    queue q;
    q.push(root);

    while(!q.empty()) {
        int levelSize = q.size();
        node* last = NULL;

        while(levelSize-- > 0) {
            node* curr = q.pop();
            if(curr!=NULL)
                last = curr;

            if(curr!=NULL) {
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        if(last != NULL)
            cout << last->num<< " ";
    }
}
int main(){
    int n,arr[100];
    cout<<"enter number of nodes: ";
    cin>>n;
    cout<<"enter node values (-1 for NULL): ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    node *root=tree(n,arr);
    cout<<"Right view of the tree: ";
    rightView(root);
}