#include <iostream>
#include <vector>
using namespace std;
int map[9][9];
vector<pair<int,int>> v;
bool row_col(int x, int y, int num){
    for(int i=0; i<9; i++){
        if(map[x][i] == num){
            return false;
        }
    }
    for(int i=0; i<9; i++){
        if(map[i][y] == num){
            return false;
        }
    }
    return true;    
}
bool matrix(int x, int y, int num){
    x = x / 3; y = y / 3;
    for(int r = x * 3 ; r < (x * 3 ) + 3 ; r ++){
        for(int c = y * 3; c < (y * 3) + 3 ; c++){
            if(map[r][c] == num){
                return false;
            }
        }
    }
    return true;
}
void dfs(int index){
    if(index == v.size()){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    for(int i=1; i<=9; i++){
        int x = v[index].first;
        int y = v[index].second;
        bool check1 = row_col(x,y,i);
        bool check2 = matrix(x,y,i);
        if(check1 && check2){
            map[x][y] = i;
            dfs(index+1);            
            map[x][y] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> map[i][j];
            if(map[i][j] == 0) v.push_back(make_pair(i,j));
        }
    }
    dfs(0);
    return 0;
}