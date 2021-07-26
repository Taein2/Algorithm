#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool check[4000001];
vector<int> prime;
int n;
int result = 0, sum = 0, lo = 0, hi = 0;

int main() {
    for (int i = 2; i < 4000001; i++) {
        if (!check[i]) {
            prime.push_back(i);
            for (int j = i*2; j < 4000001; j += i) check[j] = true;
        }
    }
    cin >> n;
	while(true){
		if( sum >= n){
			sum -= prime[lo++];
		}else if( hi == prime.size()){
			break;
		}else{
			sum += prime[hi++];
		}
		if(sum == n) result++;
	}	
	cout << result;
	return 0;
}
