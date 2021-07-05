#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(pair<int,string> a, pair<int,string> b){
    return a.first < b.first;    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
 
    vector<pair<int,string>> v(t);
    for (int i=0; i<t; i++){
        cin >> v[i].first >> v[i].second;
    }

    stable_sort(v.begin(), v.end(),cmp);
    
    for (int i=0; i < t; i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}