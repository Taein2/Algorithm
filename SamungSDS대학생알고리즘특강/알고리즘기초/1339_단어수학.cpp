#include <iostream>
#include <string>
#include <algorithm>

int n;
int alphabet[26];

using namespace std;
bool compare(int a, int b){
    if(a > b) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        int pow = 1;
        for(int j=str.length()-1; j >= 0; j--){
            alphabet[str[j] - 'A'] += pow;
            pow*=10;
        }
    }
    sort(alphabet, alphabet + 26, compare);
    int now = 9, result = 0;
    for(int i=0; i< 26; i++){
        if(alphabet[i]){
            result += alphabet[i] * now;
            now--;
        }
    }
    cout << result;
    return 0;
}