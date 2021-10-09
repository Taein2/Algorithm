#include <iostream>

using namespace std;

int gcd(int a, int b){
    if (a % b == 0){
        return b;
    }
    return gcd(b, a % b);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;

    cout << gcd(a,b) << "\n";
    cout << a * b / gcd(a,b);

    return 0;
}