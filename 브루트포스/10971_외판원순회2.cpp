#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w[1000][1000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> w[i][j];
        }
    }
    vector<int> v(n);
    for(int i=0; i<n; i++){
        v[i] = i;
    }
    int result = 99999999;
    do{
        bool ok = true;
        int sum = 0;
        for(int i=0; i<n-1; i++){
            if(w[v[i]][v[i+1]] == 0){
                ok = false;
            }else{
                sum += w[v[i]][v[i+1]];
            }
        }
        if(ok && w[v[n-1]][v[0]] != 0){
            sum += w[v[n-1]][v[0]];
            result = min(result,sum);
        }
    }while(next_permutation(v.begin()+1,v.end()));

    cout << result;
    return 0;
}