#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v(n);
void f(int low, int high, int num){
    if(low > high){
        cout << 0 << "\n";
        return;
    }
    int mid = (low+high)/2;
    if(v[mid] == num){
        cout << 1 << "\n";
        return;
    }else if(v[mid] > num){
        f(low, mid-1,num);
    }else{
        f(mid+1, high, num);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int num;
        cin >> num;
        f(0, n, num);
    }
 
    return 0;
}