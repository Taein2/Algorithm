#include <iostream>
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i=2; i<=n; i++){
		while(n % i == 0){
			n /= i;
			cout << i << "\n";
		}
	}
}