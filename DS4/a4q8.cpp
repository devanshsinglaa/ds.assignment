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
class queue{
    int a[100], front, rear,size;
    public:
    queue(){
        size=100;
        front=-1;
        rear=-1;
    }
    void enqueue(int n){
         if (front == -1) front = 0;
        a[++rear] = n;
    }
    int dequeue(){
        return a[front++];
    }
    int getsize() {
        return rear-front+1;
    }
    bool isEmpty() {
        return front==-1 || front>rear;
    }
    int peek(){ return a[front];}
};
bool sorted(queue &q, int n){
    stack s;
    int next=1;
     while (!q.isEmpty()) {
        int front = q.peek();
        q.dequeue();

        if (front == next) {
            next++;
        }
        else {
            while (!s.isEmpty() && s.peek() == next) {
                s.pop();
                next++;
            }
            s.push(front);
        }
    }
    return (next-1==n);
}
int main(){
    queue q;
    int n, val;
    cout << "enter number of elements: ";
    cin >> n;
    cout<<"enter elements: ";
    for(int i=0;i<n;i++){
        cin>>val;
        q.enqueue(val);
    }
    if (sorted(q, n))
        cout << "yes, can be arranged in increasing order." << endl;
    else
        cout << "no, cannot be arranged." << endl;
    return 0;
}