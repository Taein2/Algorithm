#include <iostream>
#include <vector>
#include <queue>

#define MAX 501
using namespace std;
int n;
int entry[MAX];
int build[MAX];
int result[MAX];
vector<int> v[MAX];
void f(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(entry[i] == 0){
            q.push(i);
            result[i] = build[i];
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i];
            entry[next]--;
            if(result[next] <= result[cur] + build[next]){
                result[next] = result[cur] + build[next];
            }
            if(entry[next] == 0) q.push(next);
        }
    }
    for(int i=1; i<=n; i++) cout << result[i] << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> build[i];
        while(true){
            int a;
            cin >> a;
            if (a == -1) break;
            v[a].push_back(i);
            entry[i]++;
        }
    }
    f();
    return 0;
}