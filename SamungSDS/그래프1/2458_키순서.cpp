#include <iostream>
using namespace std;
#define MAX 501
#define INF 987654321
int n,m;
int map[MAX][MAX];
int result = 0;
void floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            map[i][j] = INF;
        }
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        map[a][b] = 1;
    }
    floyd();
    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(map[i][j] != INF || map[j][i] != INF){
                cnt++;
            }
        }
        if(cnt == n-1) result++;
    }
    cout << result;
    return 0;
}