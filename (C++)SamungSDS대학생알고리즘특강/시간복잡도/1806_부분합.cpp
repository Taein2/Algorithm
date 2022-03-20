#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,s;
    int arr[100001];
    int result = 100001;
    cin >> n >> s;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int sum = arr[0], low= 0, high = 0 ;
    while(low <= high && high < n){
        if(sum >= s){
            result = min(result, (high - low + 1));
            if( sum == s){
                sum += arr[++high];
            }else{
                sum -= arr[low];
                low++;
            }
        }else{
            sum += arr[++high];
        }
    }
    if (result == 100001){
        cout << 0;
    }else{
        cout << result;   
    }
    return 0;
}