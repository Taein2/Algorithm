#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 51
using namespace std;

int n,m;
int map[MAX][MAX];
vector<pair<int,int>> house, chicken, v;
bool selected[14];
int result=987654321;
int distance(){
    int sum = 0;
    for(int i=0; i< house.size(); i++){
        int x = house[i].first;
        int y = house[i].second;
        int d = 987654321;
        for(int j=0; j<v.size(); j++){
            int xx = v[j].first;
            int yy = v[j].second;
            int dist = abs(xx-x) + abs(yy-y);
            d = min(d,dist);
        }
        sum += d;
    }
    return sum;
}
void selected_chicken(int index, int count){
    if(count == m){
        result = min(result, distance());
        return;
    }
    for(int i=index; i<chicken.size(); i++){
        if(selected[i]) continue;
        
        selected[i] = true;
        v.push_back(chicken[i]);
        selected_chicken(i,count+1);
        selected[i] = false;
        v.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) house.push_back(make_pair(i,j));
            if(map[i][j] == 2) chicken.push_back(make_pair(i,j));            
        }
    }
    selected_chicken(0,0);
    cout << result;
    return 0;
}