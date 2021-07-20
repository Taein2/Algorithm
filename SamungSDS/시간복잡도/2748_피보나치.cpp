#include <iostream>

using namespace std;
long long fib[91];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fib[0] = 0;
    fib[1] = 1;
    int n;
    cin >> n;
    for(int i=2; i<=n; i++){
        fib[i] = fib[i-2] + fib[i-1];
    }
    cout << fib[n];
    return 0;
}