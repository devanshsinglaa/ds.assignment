#include <iostream>
using namespace std;
class stack{
    int a[100], top;
    public:
    stack(){top=-1;}
    void push(char c){
        a[++top]=c;
    }
    int pop(){
       return  a[top--];
    }
    int peek(){
        return a[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};
bool sorted(int a[], int n){
    stack s;
    int b[100],next=1;
    for(int i=0;i<n;i++){
        s.push(a[i]);
        while(!s.isEmpty()&&s.peek()==next) {
            s.pop();
            next++;
        }
    }
    if(s.isEmpty())return true;
    else return false;
}
int main(){
    int a[50],n;
    cout<<"no of elements: ";
    cin>>n;
    cout<<"enter elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(sorted(a,n)){
        cout<<"can be sorted";
    }else cout<<"cant be sorted";
    return 0;
}