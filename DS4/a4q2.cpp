#include <iostream>
using namespace std;
class queue{
    int a[100], front, rear,size;
    public:
    queue(int n){
        size=n;
        front=-1;
        rear=-1;
    }
    void enqueue(int n){
         if (front == -1) front = 0;
        rear=(rear+1)%size;
        a[rear] = n;
        cout << n << " enqueued successfully."<<endl;
    }
    void dequeue(){
        cout<<a[front]<<" popped from stack"<<endl;
        front++;
        if(front==rear){ front=rear=-1;}
        else front=(front+1)%size;
    }
    bool isFull() {
        return (front==(rear+1)%size);
    }

    bool isEmpty() {
        return front==-1 ;
    }
    void peek(){
        if(isEmpty()){
            cout<<"queue empty"<<endl;
        }else cout<<"front element is: "<<a[front]<<endl;
    }
    void display(){
        if(isEmpty()){
            cout<<"queue empty"<<endl;
            return;
    }
    cout<<"elements in queue: ";
    while(true){
        cout<<a[front]<<" ";
        if(front==rear) break;
        front=(front+1)%size;
    }
    cout<<endl;
}
};
int main(){
    int n, choice, x;
    cout << "Enter the size of queue: ";
    cin >> n;
    queue q(n);

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> x;
                q.enqueue(x);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                if (q.isEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;
            case 6:
                if (q.isFull())
                    cout << "Queue is full.\n";
                else
                    cout << "Queue is not full.\n";
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}