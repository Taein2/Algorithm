#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string str;
    string result[1000];
    getline(cin,str);
    int l = str.length();
    for(int i=0; i< l; i++){
        result[i] = str.substr(i,l);
    }
    sort(result, result+l);
    for(int i=0; i<l; i++){
        cout << result[i] << endl;
    }
    return 0;
}