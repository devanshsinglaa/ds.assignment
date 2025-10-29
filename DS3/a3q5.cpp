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
int evaluate(string s1){
    stack s;
    for(int i=0;i<s1.length();i++){
        char c =s1[i];
         if (c>='0'&&c<='9') {
            s.push(c - '0');
        }
        else{
            int val2 = s.pop();
            int val1 = s.pop();
            int result = 0;
            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^':{
                    result=1;
                    for(int i=0;i<val2;i++){
                        result*=val1;
                        break;
                    }
                }
            }
                s.push(result);
            }
    }
    return s.pop();
}

int main(){
    string postfix;
    cout << "enter expression: ";
    cin >> postfix;
    cout<<"postfix evaluation: "<<evaluate(postfix)<<endl;
    return 0;
}