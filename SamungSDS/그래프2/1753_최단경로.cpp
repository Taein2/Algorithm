#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001
#define INF 987654321
using namespace std;
int v,e,k;
int dist[MAX];
vector<pair<int,int>> vertex[MAX];
priority_queue<pair<int,int>> pq;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> v >> e >> k;
    for(int i=0;i<e;i++){
        int a, b, c;
        cin >> a >> b >> c;
        vertex[a].push_back(make_pair(b,c));
    }
    for(int i=1; i<=v; i++) dist[i] = INF;
    pq.push(make_pair(0,k));
    dist[k] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        for(int i=0; i<vertex[here].size(); i++){
            int next = vertex[here][i].first;
            int next_cost = vertex[here][i].second;
            if(dist[next] > cost + next_cost){
                dist[next] = cost + next_cost;
                pq.push(make_pair(-dist[next],next));
            }
        }
    }
    for(int i=1; i<=v; i++){
        if(dist[i] == INF){
            cout << "INF" << "\n";
        }else{
            cout << dist[i] << "\n";
        }
    }
    return 0;
}