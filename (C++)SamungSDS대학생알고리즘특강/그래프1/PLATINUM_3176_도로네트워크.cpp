#include <iostream>
#include <utility> // pair
#include <algorithm>
#include <vector>
using namespace std;
// town max
const int TMAX = 1e5;
// dist max ; 10^5 < 2^17
const int DMAX = 17;
typedef pair<int, int> pii;
int n, k, depth[TMAX+1];
// parent[i][k] : i의  2^k 번째 조상번호
int parent[TMAX+1][DMAX+1];
// val[i][k] : i의 2^k번째 조상까지의 pair< 작은길이, 큰길이 >
pii val[TMAX+1][DMAX+1];
// < 연결된 도시 , 연결길이 > 
vector<pii> v[TMAX+1];
void makeTree(int here){ // 첫번째 부모와 깊이
    for(int i=0; i<v[here].size(); i++){
        int town = v[here][i].first;
        int base = v[here][i].second;
        if(depth[town] != 0) continue;
        depth[town] = depth[here]+1;
        parent[town][0] = here;     // 2^0번째 부모 저장
        val[town][0] = pii(base,base);  // 부모까지 작은길이 = 큰길이
        makeTree(town);        
    }
}

void fillParent(){
    for(int k=0; k<= DMAX; k++){
        for(int i=2; i<=n; i++){
            int father = parent[i][k];
            if(father){
                parent[i][k+1] = parent[parent[i][k]][k];
                val[i][k+1].first = min(val[i][k].first, val[parent[i][k]][k].first);
                val[i][k+1].second = max(val[i][k].second, val[parent[i][k]][k].second);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n-1; ++i){
	    int a, b, w;
	    cin >> a >> b >> w;
	    v[a].push_back(pii(b,w));
	    v[b].push_back(pii(a,w));
    }
    depth[1] = 1; // root
    makeTree(1);
    fillParent();
    cin >> k;
    for(int i=0; i<k; i++){
        int a,b;
        cin >> a >> b;
        int mini = 1000000;
        int maxi = 0;
        if(depth[a] < depth[b]) swap(a,b);
        int diff = depth[a] - depth[b];
        int cnt = 0;
        while(diff){
            if(diff % 2 == 1){
                mini = min(mini, val[a][cnt].first);
                maxi = max(maxi, val[a][cnt].second);
                a = parent[a][cnt];
            }
            diff /= 2;
            cnt++;
        }
        if(a != b){
            for(int k = DMAX; k>=0; k--){
                if(parent[a][k] != parent[b][k]){
                    mini = min(mini, val[a][k].first);
                    maxi = max(maxi, val[a][k].second);
                    a = parent[a][k];
                    mini = min(mini, val[b][k].first);
                    maxi = max(maxi, val[b][k].second);
                    b = parent[b][k];
                }
            }
            mini = min(mini, val[a][0].first);
            maxi = max(maxi, val[a][0].second);
            mini = min(mini, val[b][0].first);
            maxi = max(maxi, val[b][0].second);
            a = parent[a][0];
        }       
        cout << mini << " " << maxi << "\n";
    }
    return 0;
}