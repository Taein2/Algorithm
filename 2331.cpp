#include <iostream>
#include <cmath>
#define MAX_SIZE 300001
using namespace std;

int visited[MAX_SIZE];
void dfs(int a, int p){
    if(visited[a] == 2)
        return;
    int next = 0;
    visited[a]++;
    while(a){
        next += (int)pow((a % 10),p);
        a /= 10;
    }
    dfs(next,p);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,p;
    cin >> a >> p;

    dfs(a,p);

    int result = 0;
    for(int i=0; i< MAX_SIZE; i++){
        if(visited[i] == 1)
            result++;
    }
    cout << result;
    return 0;
}
