#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
#define MAX 101
using namespace std;

int n,m;
int arr[MAX][MAX];
void floyd(){
    for(int i=1; i <= n; i++){
        for(int j=1; j <= n; j++){
            for(int k=1; k <= n; k++){
                if(arr[j][i] != INF && arr[i][k] != INF)
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }   
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=1;i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[i][j] = INF;
        }
    }
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(arr[a][b] > c)
            arr[a][b] = c;
    }
    floyd();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j] == INF || i == j){
                cout << 0 << " ";
            }else{
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}