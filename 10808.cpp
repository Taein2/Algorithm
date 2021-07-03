#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    int cnt = 0;
    int lst[26] = {};
    for (int i=0; i < str.size() ; i++){
        lst[str[i] - 97]++;
    }
    for (int i=0; i< 26; i++){
        cout << lst[i] << " ";
    }
    return 0;
}