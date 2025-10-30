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
int unabletoeat(queue &std, stack &sdwch){
    int count=0;
    while(!std.isEmpty()&&!sdwch.isEmpty()){
        if(std.peek()==sdwch.peek()){
            std.dequeue();
            sdwch.pop();
            count=0;
        }
        else {
            std.enqueue(std.dequeue());
            count++;
        }
        if(count==std.getsize()) break;
    }
    return std.getsize();
}
int main(){
    queue students;
    stack sandwiches;
    int n;
    cout<<"enter no of students: ";
    cin>>n;
    int val;
    cout<<"enter student preferences: ";
    for(int i=0;i<n;i++){
        cin>>val;
        students.enqueue(val);
    }
    int x[100];
    cout<<"enter sandwiches: ";
    for(int i=0;i<n;i++){cin>>x[i];}
    for(int i=n-1;i>=0;i--){
        sandwiches.push(x[i]);
    }
    cout<<"students not able to eat: "<<unabletoeat(students, sandwiches)<<endl;
    return 0;
}