#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n,m;
int dp[1001][1001] = {0,};
int map[1001][1001];
int big_result = 0;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=m; j++){
            map[i][j] = s[j-1] - 48;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j] == 1){
                dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;

                if(big_result < dp[i][j]) big_result = dp[i][j];
            }
        }
    }
    cout << big_result * big_result;
    return 0;
}