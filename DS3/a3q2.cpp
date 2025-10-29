#include <iostream>
#include <string>
using namespace std;
class stack{
    int a[100], top;
    public:
    stack(){
        top=-1;
    }
    void push(char c){
        a[++top]=c;
    }
    char pop(){
       return  a[top--];
    }
    bool isEmpty() {
        return top == -1;
    }
};
int main(){
    string str;
    cout<<"enter string: ";
    cin>>str;
    stack s;
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }
    string s2 ="";
     while (!s.isEmpty()) {
        s2=s2+s.pop();
    }
    cout << "Reversed string: " << s2 << endl;
    return 0;
}