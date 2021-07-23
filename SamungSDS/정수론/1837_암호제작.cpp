#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX 1000001
using namespace std;
bool check[MAX];
vector<int> prime;
string s;
int k;
bool ck(int x) {
    int result = 0;
    for (int i = 0; s[i]; i++) {
        result = result * 10 + (s[i] - '0');
		result %= x;
    }
    return result == 0;
}
int main() {
    for (int i = 2; i < MAX; i++) {
        if (!check[i]) {
            prime.push_back(i);
            for (int j = i*2; j < MAX; j += i) check[j] = true;
        }
    }
    cin >> s >> k;
    for (int i = 0; i < prime.size(); i++) {
        if (prime[i] >= k) break;
        if (ck(prime[i])) {
            cout << "BAD " << prime[i];
			return 0;
        }
    }
    cout <<"GOOD";
}
