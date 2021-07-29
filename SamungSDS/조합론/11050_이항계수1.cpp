#include <iostream>

using namespace std;

int n, k;

int factorial(int a){
	int result = 1;
	for(int i=a; i>0; i--){
		result *= i;
	}
	return result;
}
int main() {
	cin >> n >> k;
	cout << factorial(n) / (factorial(k) * factorial(n-k));
	return 0;
}