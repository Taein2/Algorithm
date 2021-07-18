#include <iostream>

using namespace std;
int t[16];
int p[16];
int n;
int result = 0;
void f(int day, int sum){
    if(day == n+1){
        if(result < sum) result = sum;
        return;
    }
    if(day > n+1) return;
    f(day+t[day], sum+p[day]);
    f(day+1, sum);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> t[i] >> p[i];
    }
    f(1,0);
    cout << result << "\n";    
    return 0;
}