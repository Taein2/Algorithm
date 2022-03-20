#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(char a, char b){
    if(a > b) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n;
    cin >> n;
    long long sum = 0; bool zero = false;
    for (int i=0; i<n.length(); i++){
        sum += n[i] - '0';
        if(n[i] - '0' == 0) zero = true;        
    }
    if(sum % 3 != 0 || !zero){
        cout << -1;
    }else{
        sort(n.begin(),n.end(),cmp);
        cout << n;
    }
    return 0;
}
