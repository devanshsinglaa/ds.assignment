#include <iostream>
#include <string>
using namespace std;
class stack{
    int a[100], top;
    public:
    stack(){top=-1;}
    void push(char c){
        a[++top]=c;
    }
    char pop(){
       return  a[top--];
    }
    char peek(){
        return a[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
string postfix(string s1){
    stack s;
    string s2="";
    for(int i=0;i<s1.length();i++){
        char c =s1[i];
    
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){
        s2+=c;
    }
    else if(c=='('){s.push(c);}
    else if(c==')'){
        while(!s.isEmpty() && s.peek()!='('){
            s2+=s.pop();
        }
        if(!s.isEmpty()&&s.peek()=='('){s.pop();}}
        else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){ while (!s.isEmpty() && precedence(c) <= precedence(s.peek())){
            s2+=s.pop();
        }
        s.push(c);
    }
}
    while(!s.isEmpty()){
        s2+=s.pop();
    }
    return s2;
}

int main(){
    string infix;
    cout << "enter expression: ";
    cin >> infix;
    string exp= postfix(infix);
    cout<<"postfix expression: "<<exp<<endl;
    return 0;
}