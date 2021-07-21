#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int max_dp[3],min_dp[3];
    cin >> max_dp[0] >> max_dp[1] >> max_dp[2];
    min_dp[0] = max_dp[0]; min_dp[1] = max_dp[1]; min_dp[2] = max_dp[2];
    int tmp_max[3],tmp_min[3];
    for(int i=1;i<n;i++){
        cin >> tmp_max[0] >> tmp_max[1] >> tmp_max[2];
        tmp_min[0] = tmp_max[0];
        tmp_min[1] = tmp_max[1];
        tmp_min[2] = tmp_max[2];
        
        tmp_max[0] += max(max_dp[0],max_dp[1]);
        tmp_max[1] += max({max_dp[0],max_dp[1],max_dp[2]});
        tmp_max[2] += max(max_dp[1],max_dp[2]);
        max_dp[0] = tmp_max[0]; max_dp[1] = tmp_max[1]; max_dp[2] = tmp_max[2];

        tmp_min[0] += min(min_dp[0],min_dp[1]);
        tmp_min[1] += min({min_dp[0],min_dp[1],min_dp[2]});
        tmp_min[2] += min(min_dp[1],min_dp[2]);
        min_dp[0] = tmp_min[0]; min_dp[1] = tmp_min[1]; min_dp[2] = tmp_min[2];

    }
    cout << max({max_dp[0],max_dp[1],max_dp[2]}) << " " << min({min_dp[0],min_dp[1],min_dp[2]});

    return 0;
}