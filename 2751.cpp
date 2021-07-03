#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin >> t;
    vector<int> v;
    for (int i=0; i<t ; i++){
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    for(auto vec : v) cout << vec << "\n"; 
    return 0;
}