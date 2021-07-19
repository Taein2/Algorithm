#include <iostream>
using namespace std;
int com;
int map[101][101];
bool visited[101];
int result = 0;
void f(int now){
    if(visited[now]) return;
    visited[now] = true;
    for(int i=0; i<=com; i++){
        if(map[now][i] == 1 && !visited[i]){
            result++;
            f(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> com;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        map[x][y] = map[y][x] = 1;
    }
    f(1);
    cout << result;
    return 0;
}