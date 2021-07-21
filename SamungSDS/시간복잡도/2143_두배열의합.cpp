#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long t;
int n,m;
int a[1001],b[1001];
long long result = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    vector<int> v1,v2;
    for(int i=0; i<n; i++){
        int sum = a[i];
        v1.push_back(sum);
        for(int j=i+1; j<n; j++){
            sum += a[j];
            v1.push_back(sum);
        }
    }
    for(int i=0; i<m; i++){
        int sum = b[i];
        v2.push_back(sum);
        for(int j=i+1; j<m; j++){
            sum += b[j];
            v2.push_back(sum);
        }
    }
    sort(v2.begin(), v2.end());
    for(int i=0; i<v1.size(); i++){
        int val1 = lower_bound(v2.begin(),v2.end(),t-v1[i]) - v2.begin();
        int val2 = upper_bound(v2.begin(),v2.end(),t-v1[i]) - v2.begin();
        result += val2-val1;        
    }
    cout << result;
    return 0;
}