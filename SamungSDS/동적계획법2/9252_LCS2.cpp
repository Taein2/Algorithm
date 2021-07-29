#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;

string a,b;
int dp[MAX][MAX] = {0,};
string lcs[MAX][MAX];
void find(int i,int j){
    if(dp[i][j] == 0) return;
    if(a[i-1] == b[j-1]){
        find(i-1,j-1);
        cout << a[i-1];
    }else{
        dp[i-1][j] > dp[i][j-1] ? find(i-1,j) : find(i,j-1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    for(int i=1; i<=a.length(); i++){
        for(int j=1; j<=b.length(); j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[a.length()][b.length()] << "\n";
    find(a.length(),b.length());
    return 0;
}