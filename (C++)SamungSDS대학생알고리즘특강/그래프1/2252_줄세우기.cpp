#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 32000 + 1;
int n,m;
int degree[MAX];
vector<int> graph[MAX];
void BFS(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i=0; i < graph[node].size(); i++){
            int now = graph[node][i];
            degree[now]--;
            if(degree[now]== 0)
                q.push(now);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        degree[b]++;
    }
    BFS();
    return 0;
}