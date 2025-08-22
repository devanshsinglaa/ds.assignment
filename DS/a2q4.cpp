#include <iostream>
#include <cstring>
#include <cctype> 
using namespace std;

void concatenate(char str1[], char str2[]){
    strcat(str1, str2);
    cout << "concatenated string: "<<str1<<endl;
}

void reverseString(char str[]){
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp=str[i];
        str[i]=str[n-i-1];
        str[n-i- 1]=temp;
    }
    cout << "reversed string: " <<str<<endl;
}

void deleteVowels(char str[]){
    char result[100];
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
            result[k++] = str[i];
        }
    }
    result[k] = '\0';
    cout << "string after deleting vowels: " << result << endl;
}

void sortStrings(char arr[][100], int n) {
    char temp[100];
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
    cout << "strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

void convertCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
        else if (islower(str[i]))
            str[i] = toupper(str[i]);
    }
    cout << "Converted string: " << str << endl;
}

int main(){
    int choice;
    char str1[100], str2[100];
    char arr[10][100];
    int n;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Concatenate two strings\n";
        cout << "2. Reverse a string\n";
        cout << "3. Delete all vowels from a string\n";
        cout << "4. Sort strings alphabetically\n";
        cout << "5. Convert case of characters\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
        case 1:
            cout << "enter first string: ";
            cin>>str1;
            cout << "enter second string: ";
            cin>>str2;
            concatenate(str1, str2);
            break;

        case 2:
            cout << "enter a string: ";
            cin>>str1;
            reverseString(str1);
            break;

        case 3:
            cout << "enter a string: ";
            cin>>str1;
            deleteVowels(str1);
            break;
        case 4:
            cout << "enter number of strings: ";
            cin >> n;
            
            cout << "enter the strings:\n";
            for (int i = 0; i < n; i++) {
                cin>>arr[i];
            }
            sortStrings(arr, n);
            break;

        case 5:
            cout << "enter a string: ";
            cin>>str1;
            convertCase(str1);
            break;

        case 6:
            cout << "exiting program" << endl;
            break;  
         default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 6);

    return 0;      
}