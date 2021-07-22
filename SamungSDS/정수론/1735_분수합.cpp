#include <iostream>

using namespace std;
int gcd(long long a, long long b){
    if(b == 0) return a;
    else return gcd(b, a % b );
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c,d;
    int mo = 0 , ja = 0;
    cin >> a >> b >> c >> d;
    ja = a * d + b * c;
    mo = b*d;
    int min_num = gcd(ja,mo);
    ja /= min_num;
    mo /= min_num;
    cout << ja << " " << mo;
    return 0;
}