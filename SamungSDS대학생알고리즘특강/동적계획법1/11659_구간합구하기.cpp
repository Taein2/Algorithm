#include <iostream>

using namespace std;
int n,m;
int dp[100001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        dp[i+1] = dp[i] + num;
    }
    for(int i=0; i<m; i++){
        int a ,b;
        cin >> a >> b;
        cout << dp[b] - dp[a-1] << "\n";
    }

    return 0;
}