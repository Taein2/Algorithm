#include <iostream>

using namespace std;
int n,m;
int map[51][51];
bool visited[51][51];
int dp[51][51];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int result = 0;

int dfs(int x, int y){
    if( x < 0 || y <0 || x > n-1 || y > m-1) return 0;
    if(map[x][y] == 0) return 0;
    if(visited[x][y]){
        cout << -1;
        exit(0);
    }
    if(dp[x][y]) return dp[x][y];
    dp[x][y] = 1;

    visited[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + map[x][y] * dx[i];
        int ny = y + map[x][y] * dy[i];
        dp[x][y] = max(dp[x][y],dfs(nx,ny)+1);
    }
    visited[x][y] = false;
    return dp[x][y];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin >> c;
            if( c == 'H') map[i][j] = 0;
            else map[i][j] = c - '0';
        }
    }
    result = dfs(0,0);
    cout << result;
    return 0;
}