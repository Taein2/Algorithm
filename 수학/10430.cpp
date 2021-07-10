#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c;
    cin >> a >> b >> c;
    // 첫째 둘째 결과 같음
    cout << (a+b)%c << "\n";
    cout << ((a%c) + (b%c))%c << "\n";
    // 셋째 넷째 결과 같음
    cout << (a*b)%c << "\n";
    cout <<  ((a%c) * (b%c))%c << "\n";
}