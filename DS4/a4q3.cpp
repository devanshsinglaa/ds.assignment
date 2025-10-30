#include <iostream>
using namespace std;
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
    int peek(){
        return a[front];
    }
    void display(){
        if(isEmpty()){
            cout<<"queue empty"<<endl;
            return;
    }
    for(int i=front;i<=rear;i++){
        cout<<a[i]<<" ";
    }
}
};
void interleave(queue &q){
    int n=q.getsize();
    int half=n/2;
    queue temp;
    for(int i=0;i<half;i++){
        temp.enqueue(q.dequeue());
    }
     while(!temp.isEmpty()){
        q.enqueue(temp.dequeue());
        q.enqueue(q.dequeue());
     }
}
int main(){
    queue q;
    int n,val;
    cout<<"enter number of elements(only even): ";
    cin>>n;
    cout<<"enter elements: ";
    for(int i=0;i<n;i++){
        cin>>val;
        q.enqueue(val);
    }
    interleave(q);
    cout<<"interleaved queue: ";
    q.display();
    return 0;
}