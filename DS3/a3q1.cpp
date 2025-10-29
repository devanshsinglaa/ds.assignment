#include <iostream>
using namespace std;

class stack{
    int a[100], top;
    public:
    stack(){
        top=-1;
    }
    void push(int val){
        a[++top]=val;
        cout<<"pushed in stack"<<endl;
    }
    void pop(){
        cout<<a[top]<<" popped from stack"<<endl;
        top--;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == 100 - 1;
    }
    void peek(){
        cout<<"top element is: "<<a[top]<<endl;
    }
    void display(){
        cout<<"elements in stack: ";
        for(int i=top;i>=0;i--){
            cout<<a[i]<<" ";
        }
    }
};
int main(){
    stack s;
    int choice,value;
    while (true) {
        cout << "\n=== STACK MENU ===\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Full\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;
            case 3:
                if (s.isEmpty())
                    cout << "Stack is Empty.\n";
                else
                    cout << "Stack is NOT Empty.\n";
                break;

            case 4:
                if (s.isFull())
                    cout << "Stack is Full.\n";
                else
                    cout << "Stack is NOT Full.\n";
                break;

            case 5:
                s.display();
                break;

            case 6:
                s.peek();
                break;

            case 7:
                cout << "Exiting program.\n";
                return 0;
        }
    }
}