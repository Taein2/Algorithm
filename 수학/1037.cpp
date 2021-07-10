#include <iostream>
#include <algorithm>
using namespace std;

int arr[51];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> arr[i];
    }
    sort(arr, arr+t);

    cout << arr[0] * arr[t-1] << "\n";

    return 0;
}