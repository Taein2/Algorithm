#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // 15 * 28 * 19 = 7980 가능한 조합의 개수
    int e,s,m;
    cin >> e >> s >> m;
    int year = 1;
    while ((year-e) % 15 != 0 || (year-s) % 28 != 0 || (year-m) % 19 != 0 ) year++;
    cout << year;
    return 0;
}