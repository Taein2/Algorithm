#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
int n,m;
int memory[MAX] = {0,};
int cost[MAX] = {0,};
int dp[MAX][100000] = {0,};
int result = 987654321;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> memory[i];
    }
    for(int i=1; i<=n; i++){
        cin >> cost[i];
    }

    for(int i=1; i<= n; i++){
        for(int j=1; j<=10000; j++){
            if(cost[i] <= j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] +memory[i]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
            if(dp[i][j] >= m) result = min(result,j);
        }
    }
    cout << result;
    return 0;
}