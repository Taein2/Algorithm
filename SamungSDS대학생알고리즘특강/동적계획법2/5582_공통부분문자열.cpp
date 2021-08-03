#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[4001][4001] = {0,};
string t,s;
int result = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t; cin >> s;
    for(int i=1; i<=t.length(); i++){
        for(int j=1; j<=s.length(); j++){
            if(t[i-1] == s[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                result = max(result, dp[i][j]);
            }
        }
    }
    cout << result;
    return 0;
}