#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000 + 1
using namespace std;
int n,m;
int parent[MAX];
vector<pair<int,pair<int,int>>> edge;
int result = 0;
int find(int node) {
    if (parent[node] == node)
        return node;
    else
        return parent[node] = find(parent[node]);
}
void uni(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa != pb)
        parent[pb] = pa;
}
bool sameparent(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        edge.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(edge.begin(), edge.end());
    for(int i=1; i<=n; i++){ // 초기값
        parent[i] = i;
    }
    for(int i=0; i<m; i++){
        if(sameparent(edge[i].second.first,edge[i].second.second) == false){
            uni(edge[i].second.first,edge[i].second.second);
            result += edge[i].first;
        }
    }
    cout << result;
    return 0;
}