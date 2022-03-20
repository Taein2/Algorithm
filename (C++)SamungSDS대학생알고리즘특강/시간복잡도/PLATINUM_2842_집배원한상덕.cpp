#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 51
using namespace std;

int dx[8] = {1,1,1,-1,-1,-1,0,0};
int dy[8] = {-1,1,0,0,1,-1,1,-1};

int n;
int start_x, start_y;
char map[MAX][MAX];
int height[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> house;
vector <int> diff_height;
int result = 987654321;
void dfs(int x, int y, int left, int right){
    if(height[x][y] < left || height[x][y] >right) return;
    visited[x][y] = true;
    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(height[nx][ny] < left || height[nx][ny] > right) continue;
        if(visited[nx][ny]) continue;
        visited[nx][ny] = true;

        dfs(nx,ny,left,right);
    }    
}

void solve(){
    int left_num = 0, right_num = 0;
    while(true){
        if(right_num == diff_height.size()) break;
        while(true){
            int check = 0;
            memset(visited, false, sizeof(visited));
            dfs(start_x,start_y,diff_height[left_num],diff_height[right_num]);
            for(int i=0; i<house.size(); i++){
                if(visited[house[i].first][house[i].second]){
                    check += 1;
                }
            }
            if(check != house.size()) break;
            result = min(result, diff_height[right_num] - diff_height[left_num]);
            left_num++;
        }
        right_num++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] == 'P'){
                start_x = i;
                start_y = j;
            }else if(map[i][j] == 'K'){
                house.push_back(make_pair(i,j));
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> height[i][j];
            diff_height.push_back(height[i][j]);
        }
    }
    
    // 고도 값 오름차순
    sort(diff_height.begin(), diff_height.end());
    // 중복값 제거
    diff_height.erase(unique(diff_height.begin(), diff_height.end()),diff_height.end());
    
    solve();

    cout << result;
    return 0;
}