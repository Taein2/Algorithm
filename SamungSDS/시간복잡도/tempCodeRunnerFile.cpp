#include <iostream>
#include <algorithm>
using namespace std;
int n;
int map[100001][3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int max_dp[3],min_dp[3];
    cin >> max_dp[0] >> max_dp[1] >> max_dp[2];
    min_dp[0] = max_dp[0]; min_dp[1] = max_dp[1]; min_dp[2] = max_dp[2];
    int a,b,c;
    for(int i=1;i<n;i++){
        cin >> a >> b >> c;
        max_dp[0] += max(a,b);
        max_dp[1] += max(max(a,b),c);
        max_dp[2] += max(b,c);

        min_dp[0] += min(a,b);
        min_dp[1] += min(min(a,b),c);
        min_dp[2] += min(b,c);
    }
    cout << max(max(max_dp[0],max_dp[1]),max_dp[2]) << " " << min(min(min_dp[0],min_dp[1]),min_dp[2]);

    return 0;
}