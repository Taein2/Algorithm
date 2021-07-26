#include <iostream>
#include <vector>
using namespace std;

vector<int> root; 
int find(int node) {
    if (root[node] == node)
        return node;
    else
        return root[node] = find(root[node]);
}
void uni(int a, int b){
    int u = find(a);
    int v = find(b);
    root[u] = v;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int n,m;
    int cmd,a,b;
    cin >> n >> m;
    for(int i=0; i<=n;i++){
        root.push_back(i);
    }
    for(int i=0; i<m; i++){
        cin >> cmd >> a >> b;
        if( cmd == 0){
            uni(a,b);
        }else{
            if(find(a) == find(b)){
                cout << "YES" << "\n";
            }else{
                cout << "NO" << "\n";
            }
        }
    }
    return 0;
}