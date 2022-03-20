#include <iostream>
#include <vector>
using namespace std;
int n,m;
int map[1025][1025] = {0,};
int dp[1025][1025];
vector<pair<pair<int,int>, pair<int,int>>> cmd;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
        }
    }
    for(int i=0; i<m; i++){
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        cout << dp[xx][yy] - dp[xx][y-1] - dp[x-1][yy] + dp[x-1][y-1] << "\n";
    }

    return 0;
}