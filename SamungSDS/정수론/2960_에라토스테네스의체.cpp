#include <iostream>

using namespace std;
int n,k;
int arr[1001];
int result =0, cnt=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
       
    cin >> n >> k;
    for(int i=2; i<=n;i++){
        for(int j=i; j<=n; j+=i){
            if(arr[j] == 0){
                cnt++; arr[j] = 1;
            }
            if(cnt == k){
                result = j;
                break;
            }
        }
        if(cnt == k) break;
    }
    cout << result;
    return 0;
}