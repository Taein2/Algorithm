#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000000

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> v(MAX+1, 1);
    for(int i=2; i<=MAX; i++){
        for(int j=1; i*j <=MAX ; j++){
            v[i*j] += i;
        }
    }
    vector<long long> v2(MAX+1);
    for(int i=1; i<=MAX; i++){
        v2[i] = v2[i-1] + v[i];
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << v2[n] << "\n";
    }
    return 0;
}