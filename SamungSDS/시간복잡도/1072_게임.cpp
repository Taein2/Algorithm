#include <iostream>

using namespace std;
int x,z;
long long y;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x >> y;
    z = (y* 100)/x ;
    if(z >= 99){
        cout << -1;
        exit(0);
    }
    int low = 0, high = 1000000000;
    int result = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        int zz = 100 * (mid + y) / (mid + x);
        if(zz > z){
            high = mid - 1;
        } else{
            result = mid + 1;
            low = mid + 1;
        }
    }
    cout << result;
    return 0;
}