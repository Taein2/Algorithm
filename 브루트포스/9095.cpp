#include <iostream>

using namespace std;
int arr[11];
int f(int n){      // f(x) = f(x-1) + f(x-2) + f(x-3)
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i=4; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    return arr[n];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << f(n) << "\n";
    }
    return 0;
}