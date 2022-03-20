#include <iostream>
#include <algorithm>
using namespace std;
long long n,m;
long long tree[1000001];
long long result =0;
void f(long long low, long long high){
    if( low > high) return;

    long long mid = (low+high)/2;
    long long sum = 0;

    for(int i=0; i<n; i++){
        if(tree[i] > mid){
            sum += tree[i] - mid;
        }
    }
    if(sum >= m){
        if(result < mid)
            result = mid;
        f(mid+1,high);
    }else{
        f(low,mid-1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> tree[i];
    }   
    sort(tree, tree+n);
    f(0, 1000000000);
    cout << result;
    return 0;
}
