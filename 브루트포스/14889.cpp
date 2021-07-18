#include <iostream>
#include <vector>
using namespace std;
int s[20][20];
int n;
int f(int index, vector<int> &first, vector<int> &second){
    if(index == n){
        if( first.size() != n/2) return -1;
        if( second.size() != n/2) return -1;
        int t1 = 0;
        int t2 = 0;
        for(int i=0; i< n/2; i++){
            for(int j=0; j< n/2; j++){
                if(i == j) continue;
                t1 += s[first[i]][first[j]];
                t2 += s[second[i]][second[j]];
            }
        }
        int diff = t1 -  t2;
        if (diff < 0) diff = - diff;
        return diff;
    }
    if( first.size() > n/2) return -1;
    if( second.size() > n/2) return -1;
    int result = -1;
    first.push_back(index);
    int t1 = f(index+1, first,second);
    if( result == -1 || (t1 != -1 && result > t1)) result = t1;
    first.pop_back();
    second.push_back(index);
    int t2 = f(index+1, first, second);
    if( result == -1 || (t2 != -1 && result > t2)) result = t2;
    second.pop_back();
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> s[i][j];
        }
    }
    vector<int> first, second;    
    cout << f(0,first,second) << "\n";
    return 0;
}