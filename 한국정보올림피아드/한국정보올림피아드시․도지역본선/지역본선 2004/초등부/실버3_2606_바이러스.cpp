#include <iostream>
#include <vector>
using namespace std;

int t;
int n;
vector<int> v[101];
bool check[101];
int result = 0;
void dfs(int x){
    check[x] = true;
    for (int i=0; i<v[x].size(); i++){
        int y = v[x][i];
        if(!check[y]){
            dfs(y);
            result++;
        }        
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);  v[y].push_back(x);
    }
    dfs(1);
    cout << result;
    return 0;
}