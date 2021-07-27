#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define TMAX 100000+1
#define DMAX 18
using namespace std;

int n,m,MAXK;
int parent[TMAX][DMAX];
int depth[TMAX];
bool visited[TMAX];
vector<int> e[TMAX];
//dfs
void makeTree(int here, int dep){ // 첫번째 부모와 깊이
    visited[here] = true;
    depth[here] = dep;
    for(int i=0; i<e[here].size(); i++){
        int next = e[here][i];
        if(visited[next]) continue;
        parent[next][0] = here;
        makeTree(next, dep+1); 
    }
}
void fillParent(){
    for(int k=1; k<= MAXK; k++){
        for(int i=1; i<=n; i++){
            parent[i][k] = parent[parent[i][k-1]][k-1];
        }
    }
}
int lca(int swall, int deep){
    if(depth[deep] < depth[swall]) swap(deep,swall);

    for(int k=MAXK; k >=0; k--){    //높이 맞춰주기
        int diff = depth[deep] - depth[swall];
        if(diff >= (1<<k)) deep = parent[deep][k];
    }
    if(deep == swall) return deep;

    for(int k=MAXK; k >=0; k--){    
        if(parent[deep][k] != parent[swall][k]){
            deep = parent[deep][k];
            swall = parent[swall][k];
        }
    }
    return parent[deep][0];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n-1; i++){ // node n 개 간선 n-1개
        int a,b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    makeTree(1,0); // root 1 , root depth 0
    MAXK = (int)floor(log2(n));
    fillParent();
    cin >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        cout << lca(a,b) << "\n";
    }
    return 0;
}