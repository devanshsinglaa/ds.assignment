#include <iostream>
using namespace std;
class PriorityQueue {
public:
    int a[1000];
    int n;
    PriorityQueue() { n=0; }
    void insert(int x) {
        a[n]=x;
        int i=n;
        n++;
        while(i>0 && a[(i-1)/2] < a[i]) {
            swap(a[(i-1)/2], a[i]);
            i=(i-1)/2;
        }
    }
    int getMax() {
        if(n==0) return -1;
        return a[0];
    }
    int extractMax() {
        if(n==0) return -1;
        int x=a[0];
        a[0]=a[n-1];
        n--;
        heapify(0);
        return x;
    }
    void heapify(int i) {
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<n && a[l]>a[largest]) largest=l;
        if(r<n && a[r]>a[largest]) largest=r;
        if(largest!=i){
            swap(a[i],a[largest]);
            heapify(largest);
        }
    }
};
int main() {
    PriorityQueue pq;
    pq.insert(10);
    pq.insert(5);
    pq.insert(20);
    pq.insert(1);

    cout<<pq.getMax()<<endl;
    cout<<pq.extractMax()<<endl;
    cout<<pq.extractMax()<<endl;
}