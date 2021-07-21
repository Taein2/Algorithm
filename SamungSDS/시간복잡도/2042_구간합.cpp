#include <iostream>

using namespace std;
int n,m,k;
int arr[100001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
    }

    return 0;
}