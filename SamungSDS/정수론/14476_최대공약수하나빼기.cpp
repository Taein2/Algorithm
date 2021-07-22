#include <iostream>

using namespace std;
#include <iostream>

using namespace std;
int arr[1000010];
int lgcd[1000010], rgcd[1000010];
int gcd(long long a, long long b){
    if(b == 0) return a;
    else return gcd(b, a % b );
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=1;i<=n;i++) lgcd[i] = gcd(arr[i],lgcd[i-1]);
    for(int i=n; i>=1;i--) rgcd[i] = gcd(arr[i],rgcd[i+1]);
    int del_num=-1,result=0;
    for(int i=1; i<=n; i++){
        int temp = gcd(lgcd[i-1],rgcd[i+1]);
        if(temp > result && (arr[i] % temp)){
            result = temp;
            del_num = arr[i];
        }
    }
    if (del_num == -1) cout << -1;
    else cout << result << " " << del_num;
    return 0;
}