#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v;
    int hap = 0;
    for(int i=0; i<9; i++){
        int n;
        cin >> n;
        hap += n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<9; i++){
        for (int j= i+1; j < 9; j++){
            if( hap - v[i] - v[j] == 100){
                for(int k=0; k<9; k++){
                    if (i ==k || j == k) continue;
                    cout << v[k] << "\n";
                }
                return 0;
            }
        }
    }
    return 0;
}