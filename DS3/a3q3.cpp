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
bool balanced(string s1){
    stack s;
    for(char c:s1){
        if(c == '(' || c == '{' || c == '['){
            s.push(c);
        }else if(c == ')' || c == '}' || c == ']'){
            if(s.isEmpty()) return false;
             char top = s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                    return false;
            }
        }
    }   
    return s.isEmpty();
}
int main(){
    string str;
    cout<<"enter expression: ";
    cin>>str;
    if(balanced(str)){
        cout << "The expression is balanced.\n";}
    else{
        cout << "The expression is NOT balanced.\n";}
        return 0;
}