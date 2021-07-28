#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int MAX = 10000;
int dfnum[MAX+1];
vector<int> adj[MAX+1];
int v,e,df;
set<int> result;
int dfs(int here, bool isroot){
    dfnum[here] = df;
    df++;
    int ret = dfnum[here];
    
    int child = 0; // 자식 트리 수
    
    for(int i=0; i < adj[here].size(); i++){
        int next = adj[here][i];
        
        if(dfnum[next]){
            ret = min(ret, dfnum[next]);
            continue;
        }
        child++;
        int prev = dfs(next,false);
        
        if(!isroot && prev >= dfnum[here]) // 정점 A가 루트가 아니면 A번 정점에서 자식 노드들이 A를 거치지 않고 정점 A보다 빠른 방문번호를 가진 곳으로 갈 수 없다면
            result.insert(here);
        ret = min(ret,prev);
    }
    if(isroot && child >= 2) // 정점 A가 루트, 자식 수가 2개 이상
        result.insert(here);
    return ret;

}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
    df = 1;
    for(int i=1; i<=v; i++){
        if(!dfnum[i]){
            dfs(i,true);
        }
    }
    cout << result.size() << "\n";
    for ( auto i : result){
        cout << i << " ";
    }
    return 0;
}