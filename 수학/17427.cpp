#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long result = 0;
    for(int i=1; i<=n; i++){
        result += (n/i)*i;
    }
    cout << result;
    return 0;
}