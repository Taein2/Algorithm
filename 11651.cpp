#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int,int> a, pair<int,int> b) {
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m;
    cin >> t;
    vector<pair<long,long>> v;
    for (int i=0; i< t; i++){
        cin >> n >> m;
        v.push_back(make_pair(n,m));
    }
    sort(v.begin(), v.end(),compare);  

    for (int i=0; i< v.size(); i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}