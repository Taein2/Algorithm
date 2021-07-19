#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recommend[101] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> v(n);
    for(int i=0; i<m; i++){
        int num;
        cin >> num;
        recommend[num]++;
        bool change = true;
        for(int j=0;j<n; j++){
            if(v[j].second == 0){
                v[j].second = num;
                v[j].first = i;
                change = false;
                break;
            }else if(v[j].second == num){
                change = false;
                break;
            }
        }
        if(change){
            int idx = 0;
            for(int j=1; j<n; j++){
                if(recommend[v[j].second] == recommend[v[idx].second]){
                    if(v[j].first < v[idx].first) idx = j;
                }else if(recommend[v[j].second] < recommend[v[idx].second]){
                    idx = j;
                }
            }
            recommend[v[idx].second] = 0;

            v[idx].first = i;
            v[idx].second = num;
        }
    }
    vector<int> result;
    for(int i=0; i<n; i++){
        result.push_back(v[i].second);
    }
    sort(result.begin(), result.end());
    for(int i=0; i<n;i++){
        cout << result[i] << " ";
    }
       
    return 0;
}