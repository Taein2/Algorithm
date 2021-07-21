#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[4001][4];
vector<int> v1,v2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v1.push_back(arr[i][0] + arr[j][1]);
            v2.push_back(arr[i][2] + arr[j][3]);
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    long long result = 0;
    for(int i=0; i<v1.size(); i++){
        int val1 = lower_bound(v2.begin(),v2.end(),-v1[i]) - v2.begin();
        int val2 = upper_bound(v2.begin(),v2.end(),-v1[i]) - v2.begin();
        result += val2 - val1;
    }
    cout << result;
    return 0;
}