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
    int peek(){ return a[front];}
};
void binarynumbers(int n){
    queue q;
    q.enqueue(1);
    for(int i=0;i<n;i++){
        int num = q.dequeue();
        cout<<num<<" ";

        q.enqueue(num*10);
        q.enqueue(num*10+1);
    }
}
int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;
    cout<<"binary numbers upto "<<n<<" are: ";
    binarynumbers(n);
    return 0;
}