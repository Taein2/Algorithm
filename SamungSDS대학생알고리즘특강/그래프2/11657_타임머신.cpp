#include <iostream>
#include <vector>
#define MAX 501
#define ll long long
#define INF 987654321
using namespace std;
int n,m;
ll dist[MAX];
vector<pair<pair<int,int>,int>> v;
void velman(){
    dist[1] = 0;
    for(int i=1; i <= n-1; i++){
        for(int j=0; j<v.size(); j++){
            int from = v[j].first.first;
            int to = v[j].first.second;
            int cost = v[j].second;
            if(dist[from] == INF) continue;
            if(dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
        }
    }
    for(int i=0; i<v.size(); i++){
        int from = v[i].first.first;
        int to = v[i].first.second;
        int cost = v[i].second;

        if(dist[from] == INF) continue;
        if(dist[to] > dist[from] + cost){
            cout << -1 << "\n";
            return;
        }
    }
    for(int i=2; i<=n; i++){
        if(dist[i] == INF) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back(make_pair(make_pair(a,b),c));
    }    

    velman();
    return 0;

}