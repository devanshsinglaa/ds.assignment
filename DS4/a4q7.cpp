#include <iostream>
using namespace std;

class queue {
    int a[100];
    int front, rear;
public:
    queue() { front = -1; rear = -1; }
    
    void enqueue(int x) {
        if (front == -1) front = 0;
        a[++rear] = x;
    }
    
    int dequeue() {
        return a[front++];
    }
    
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
    
    int size() {
        return rear - front + 1;
    }
    
    int peek() {
        return a[front];
    }

    void display() {
        for (int i = front; i <= rear; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};
int minIndex(queue &q, int sortIndex) {
    int min_index = -1, min_val = 1e9;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.dequeue();

        if (curr < min_val && i <= sortIndex) {
            min_val = curr;
            min_index = i;
        }

        q.enqueue(curr);
    }

    return min_index;
}

void moveMinToRear(queue &q, int min_index) {
    int n = q.size();
    int min_val;

    for (int i = 0; i < n; i++) {
        int curr = q.dequeue();

        if (i == min_index)
            min_val = curr;
        else
            q.enqueue(curr);
    }

    q.enqueue(min_val);
}

void sortQueue(queue &q) {
    int n = q.size();
    for (int i = 1; i <= n; i++) {
        int min_index = minIndex(q, n - i);
        moveMinToRear(q, min_index);
    }
}

int main() {
    queue q;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.enqueue(val);
    }

    cout << "Original queue: ";
    q.display();

    sortQueue(q);

    cout << "Sorted queue: ";
    q.display();

    return 0;
}