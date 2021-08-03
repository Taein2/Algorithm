#include <iostream>

using namespace std;
int dp[1001][1001];
int n,k;
int nCr(int n, int r){
    if(r == 0){
        return 1;
    }
    if (n < r || n < 0 || n > 1000 || r < 0 || r > 1000) return 0;
    if(dp[n][r] != -1){
        return dp[n][r];
    }
    int tmp = (nCr(n-1,r-1) + nCr(n-1, r)) % 10007; 
    dp[n][r] = tmp;
    return dp[n][r];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1 ; i <= 1000 ; i++) {
        for (int j = 1 ; j <= 1000 ; j++) {
            dp[i][j] = -1;
        }
    }
    cin >> n >> k;
    cout << nCr(n,k);
    return 0;
}