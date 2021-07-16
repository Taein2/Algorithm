#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long result = 0;
    for(int start = 1, len = 1; start <= n; start *= 10 ,len++){
        int end = start * 10 - 1;
        if( end > n ){
            end = n;
        }
        result += (long long)(end - start + 1) * len;
    }   
    cout << result;
    return 0;
}