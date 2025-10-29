#include <iostream>
#include <string>
using namespace std;
bool anagram(string &s1, string &s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    int freq[26]={0};
    for(int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
    }
    for(int i = 0; i < s2.length(); i++) {
        freq[s2[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++) {
        if (freq[i] != 0)
            return false;
    }
    return true;
}
int main(){
    string str1, str2;
    cout << "enter first string: ";
    cin >> str1;
    cout << "enter second string: ";
    cin >> str2;
    if(anagram(str1, str2))
        cout << "they are anagrams.\n";
    else
        cout << "they are not anagrams.\n";
    return 0;
}