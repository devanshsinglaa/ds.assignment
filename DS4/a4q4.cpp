#include <iostream>
#include <string>
using namespace std;
class queue{
    int a[100], front, rear,size;
    public:
    queue(){
        size=100;
        front=-1;
        rear=-1;
    }
    void enqueue(char n){
         if (front == -1) front = 0;
        a[++rear] = n;
    }
    char dequeue(){
        return a[front++];
    }
    int getsize() {
        return rear-front+1;
    }
    bool isEmpty() {
        return front==-1 || front>rear;
    }
    char peek(){
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
void nonrepeating(string str){
    queue q;
    int freq[26]={0};
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        freq[ch-'a']++;
        q.enqueue(ch);
        while(!q.isEmpty()&&freq[q.peek()-'a']>1){
        q.dequeue();
    }
    if(q.isEmpty()) cout<<"-1";
    else cout<<q.peek();
    }
}
int main(){
    string s;
    cout<<"enter string w no spaces: ";
    cin>>s;
    cout<<"new string: ";
    nonrepeating(s);
    return 0;
}