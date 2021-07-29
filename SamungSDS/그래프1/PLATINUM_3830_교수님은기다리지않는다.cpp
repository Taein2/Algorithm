#include <iostream>
typedef long long ll;
using namespace std;
const int MAX = 1e5;
int n,m;
ll parent[MAX+1];
ll diff[MAX+1];
ll result = 0;
ll find(ll node) {
    if (parent[node] == node)
        return node;
    else{
        int tmp = parent[node];
        parent[node] = find(parent[node]);
        diff[node] += diff[tmp];
        return parent[node];
    }
}
void uni(ll a, ll b, ll c){
    if(a > b){
        ll t = a;
        a = b; b = t;
        c = -c;
    }
    find(a); find(b);
    ll x = diff[b];
    ll y = diff[a];
    a = find(a); 
    b = find(b);
    parent[b] = a; 
    diff[b] = c + y - x;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i=1; i<=n; i++){
            parent[i] = i;
            diff[i] = 0;
        }

        for(int i=0; i<m; i++){
            char a;
            cin >> a;
            if(a == '!'){
                int x,y,z;
                cin >> x >> y >> z;
                uni(x,y,z);
            }else{
                int x,y;
                cin >> x >> y;
                if(find(x) == find(y)){
                    cout << diff[y] - diff[x] << "\n";
                }else{
                    cout << "UNKNOWN" << "\n";
                }
            }
        }
    }
    return 0;
}