#include <iostream>
using namespace std;

int a[100];
int n;

void create(){
    cout<< "enter number of elements: ";
    cin>>n;
    cout<<"enter elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
void display(){
    cout<<"elements in array are: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}
void insert(){
    int pos,value;
    cout<<"enter position where to add: ";
    cin>>pos;
    cout<<"enter element to add: ";
    cin>>value;
    for(int i=n;i>=pos; i--){
        a[i]=a[i-1];
    }
    a[pos - 1] = value;
    n++;
}
void deleteEl(){
    int pos;
    cout<<"enter position from where element has to be deleted: ";
    cin>>pos;
    for (int i=pos-1;i<n-1; i++) {
        a[i]=a[i+1];
    }
    n--;
}
void linearSearch(){
    int val;
    cout<<"enter value to search: ";
    cin>>val;
    for(int i=0;i<n;i++) {
        if (a[i] == val) {
            cout << "Element found at position " << i + 1 << endl;
            return;
        }
    }
}

int main(){
    int choice;
    do {
        cout<< "\n——MENU——\n";
        cout<< "1. CREATE\n";
        cout<< "2. DISPLAY\n";
        cout<< "3. INSERT\n";
        cout<< "4. DELETE\n";
        cout<< "5. LINEAR SEARCH\n";
        cout<< "6. EXIT\n";
        cout<< "enter your choice: ";
        cin >>choice;

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: deleteEl(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program."<<endl; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}