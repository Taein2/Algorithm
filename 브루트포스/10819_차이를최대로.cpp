#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int calculator(vector<int> &v){
    int result = 0;
    for(int i=1; i < n; i++){
        result += abs(v[i-1] - v[i]);
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int result = 0;
    do{
        int temp = calculator(v);
        result = max(temp, result);
    }while(next_permutation(v.begin(),v.end()));
    cout << result;
    return 0;
}