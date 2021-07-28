#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[501][501] = {0,};
int arr[501][501];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin >> arr[i][j];
        }
    }
    dp[1][1] = arr[1][1];
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
        }
    }
    int max_result = 0;
    for(int i=1; i<=n; i++){
        if(max_result < dp[n][i]) max_result = dp[n][i];
    }
    cout << max_result;
    return 0;
}