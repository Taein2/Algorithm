#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    vector<vector<int>> v(t, vector<int>(2,0));
    for(int i=0; i<t; i++){
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin(),v.end());

    for(int i=0; i<v.size(); i++){
        cout << v[i][0] << " " << v[i][1] << "\n";
    }
    
    return 0;
}