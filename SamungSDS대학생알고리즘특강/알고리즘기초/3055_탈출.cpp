#include <iostream>
#include <queue>
using namespace std;
int r,c;
char map[51][51];
bool visited[51][51];
queue<pair<int,int>> water;
queue<pair<int,int>> start;
int destination_x,destination_y;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 ,0 };
void bfs(){
	int result = 0;
	while (!start.empty()) {
		result++;
		int water_size = water.size(); 
		while (water_size--) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (map[nx][ny] == 'X' || map[nx][ny] == 'D' || map[nx][ny] == '*') continue;
				water.push(make_pair(nx, ny));
				map[nx][ny] = '*';
			}
		}

		int start_size = start.size();
		while (start_size--) {
			int x = start.front().first;
			int y = start.front().second;
			start.pop();

			visited[x][y] = true;
			if (x == destination_x && y == destination_y) {
				cout << result - 1 << "\n";
				return;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (map[nx][ny] == 'X' || map[nx][ny] == '*' || visited[nx][ny]) continue;
				visited[nx][ny] = true;
				start.push(make_pair(nx, ny));
			}
		}
	}
	cout << "KAKTUS" << "\n";
	return;
}int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> map[i][j];
            if(map[i][j] == 'S') start.push(make_pair(i,j)); 
            if(map[i][j] == 'D'){
                destination_x = i;
                destination_y = j;
            }  
            if(map[i][j] == '*') water.push(make_pair(i,j));
        }
    }
    bfs();
    return 0;
}