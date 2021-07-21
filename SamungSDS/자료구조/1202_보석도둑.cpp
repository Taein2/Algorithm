#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,k;
long long result = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<pair<int,int>> v1(n);
    vector<int> v2(k);
    priority_queue<long long> pq;
    for(int i=0; i<n; i++){
        cin >> v1[i].first >> v1[i].second;
    }
    for(int i=0; i<k; i++){
        cin >> v2[i];
    }
    sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());
    int index = 0;
    for(int i=0; i<k; i++){
        while(index < n && v1[index].first <= v2[i]){
            pq.push(v1[index].second);
            index++;
        }
        if(!pq.empty()){
            result += pq.top();
            pq.pop();
        }
    }
    cout << result;

    return 0;
}