#include <iostream>

using namespace std;
int gcd(int a, int b){
    if( b == 0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    int result;
    cin >> a >> b;
    result = gcd(a,b);
    cout << result << "\n";
    cout << a*b / result << "\n";
    return 0;
}