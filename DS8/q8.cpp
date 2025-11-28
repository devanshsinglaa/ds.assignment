#include <iostream>
using namespace std;
struct node{
    int num;
    node *left, *right;
    node(int n): num(n), left(NULL), right(NULL) {}
};
struct trees{
    node *list[100];
    int count;
    trees(){count =0;}
};
class bst{
    public:
    trees generate(int start, int end){
        trees result;
        if(start>end){
            result.list[result.count++]=NULL;
            return result;
        }
        for(int root=start;root<=end;root++){
            trees leftsubtree=generate(start, root-1);
            trees rightsubtree=generate(root+1,end);
            for(int i=0;i<leftsubtree.count;i++){
                for(int j=0;j<rightsubtree.count;j++){
                    node *newnode=new node(root);
                    newnode->left=leftsubtree.list[i];
                    newnode->right=rightsubtree.list[j];
                    result.list[result.count++]=newnode;
                }
            }
        }
        return result;
    }
    trees generatebsts(int n){
        return generate(1,n);
    }
};
int main(){
    bst b;
    trees t=b.generatebsts(3);
    cout<<"Total BSTs with 3 nodes: "<<t.count<<endl;
    return 0;
}