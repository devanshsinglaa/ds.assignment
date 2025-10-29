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
int nearestsmall(int a[], int n){
    stack s;
    for(int i=0;i<n;i++){
        while(!s.isEmpty()&&s.peek()>=a[i]){
            s.pop();
        }
        if(s.isEmpty()){cout<<-1<<" ";}
        else {cout<<s.peek()<<" ";}
        s.push(a[i]);
    }
}
int main(){
    int a[50],n;
    cout<<"no of elements: ";
    cin>>n;
    cout<<"enter elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"output matrix: ";
    nearestsmall(a,n);
    return 0;
}