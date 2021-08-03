#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int s[500001],z[500001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,h;
    cin >> n >> h;
    for(int i = 0; i< n; i++){
        int num;
        cin >> num;
        if(i%2 == 0) s[num]++; 
        else z[num]++;
    }
    for(int i= h-1; i >= 1; i--){
        s[i] += s[i+1];
        z[i] += z[i+1];
    }
    vector<int> v;
    for(int i=1; i<= h; i++){
        v.push_back(s[i] + z[h-i+1]);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for(int i=1; i<v.size(); i++){
        if(v[i] == v[0]) cnt++;
        else break;
    }
    cout << v[0] << " " << cnt+1;
        
    return 0;
}