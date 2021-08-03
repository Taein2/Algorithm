#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 500001
#define ll long long

using namespace std;
int n;
ll tree[MAX*4];
int bound[MAX];

vector<int> v;
ll sum(int index, int start, int end, int left, int right){
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[index];
    int mid = (start+end)/2;
    return sum(index*2, start, mid, left, right) + sum(index*2+1, mid+1, end, left, right);
}
int update(int index, int start, int end, int changed, int diff){
    if(end < changed || changed < start) return tree[index];
    if(start == end) return tree[index] = diff;
    int mid = (start+end)/2;
    return tree[index] = update(index*2, start, mid, changed, diff) + update(index*2+1, mid+1, end, changed, diff);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> bound[i];
        v.push_back(bound[i]);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        int index =lower_bound(v.begin(), v.end(), bound[i]) - v.begin();
        update(1,0,n-1,index,1);
        cout << (i+1) - sum(1,0,n-1,0,index-1) << "\n";
    }
    return 0;
}
