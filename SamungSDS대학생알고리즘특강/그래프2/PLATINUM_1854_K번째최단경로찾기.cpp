#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int,int> 
using namespace std;

int n,m,k;
vector<pii> v[1001];
priority_queue<int> heap[1001]; // 최대 힙
void dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,1}); // 거리 , 도시
    heap[1].push(0);
    while(!pq.empty()){
        int d = -pq.top().first;
        int x = pq.top().second;
        pq.pop();
        for (pii next : v[x]){
            int nx = next.first;
            int nd = d + next.second;
            if(heap[nx].size() < k || heap[nx].top() > nd){
                if(heap[nx].size() == k){
                    heap[nx].pop();
                }
                heap[nx].push(nd);
                pq.push({-nd, nx});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    dijkstra();
    for(int i=1; i<=n; i++){
        if(heap[i].size() == k){
            cout << heap[i].top() << "\n";
        }else{
            cout << -1 << "\n";
        }
    }
    return 0;
}