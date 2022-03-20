#include <iostream>
#include <stack>
#include <vector>
#define MAX 1000000
using namespace std;
int n;
int arr[MAX+1]; 
int dp[MAX+1];      // 만들 수 있는 x의 길이의 LIS 성분
vector<int> st;
int cnt = 0;
vector<int> result;
stack<int> print;
int lis(){
    result.push_back(arr[1]);
    for(int i=2; i<=n; i++){
        if(result[cnt] < arr[i]){
            result.push_back(arr[i]);
            cnt++;
            dp[i] = cnt;
        }else{
            int pos = lower_bound(result.begin(), result.end(), arr[i]) - result.begin();
            result[pos] = arr[i];
            dp[i] = pos;
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    cnt = lis();
    cout << cnt+1 << "\n";
    for(int i=n; i>=1; i--){
        if(dp[i] == cnt){
            print.push(arr[i]);
            cnt--;
        }
    }
    while(!print.empty()){
        cout << print.top() << " ";
        print.pop();
    }
    return 0;
}