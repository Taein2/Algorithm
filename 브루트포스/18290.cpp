#include <iostream>

using namespace std;
int a[10][10];
bool c[10][10];
int n,m,k;
int result = -2147483647;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void f(int px, int py, int cnt, int sum){
    if (cnt == k){
        if(result < sum) result = sum;
        return;
    }
    for(int x= px; x< n; x++){
        for (int y =(x == px ? py : 0) ; y < m; y++){
            if(c[x][y]) continue;
            bool ok = true;
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if( nx >= 0 && nx < n && ny >=0 && ny <m){
                    if(c[nx][ny]) ok= false;
                }
            }
            if(ok){
                c[x][y] = true;
                f(x,y,cnt+1, sum+a[x][y]);
                c[x][y] = false;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i=0; i< n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    f(0,0,0,0);
    cout << result << "\n";
    return 0;
}