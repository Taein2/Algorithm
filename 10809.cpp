#include <iostream>
#include <string>

using namespace std;

int main(void){
    string str;
    string chk = "abcdefghijklmnopqrstuvwxyz";
    cin >> str;
    for (int i=0; i< chk.length(); i++){
        cout << (int)str.find(chk[i]) << " ";
    }
    return 0;
}