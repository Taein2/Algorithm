#include <iostream>
#include <string>
using namespace std;
int k;
int getLength(int n){
    int len = 0;
    for(int start=1,l=1; start <= n; start *= 10 ,l++){
        int end = start * 10 -1;
        if(end > n) end = n;
        len += ((end-start)+1 ) * l;
    }
    return len;
}
void f(int start, int end){
    int pos;
    while(start <= end){
        int mid = (start+end)/2;
        int length = getLength(mid);
        if(length < k){
            start = mid + 1;
        }else{
            pos = mid;
            end = mid - 1;
        }
    }
    int c = getLength(pos);
    string str = to_string(pos);
    cout << str[str.size() - 1 - (c-k)];
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n >> k;
    if (getLength(n) < k){
        cout << -1;
        return 0;
    }
    f(1,n);
    return 0;
}