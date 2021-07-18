#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int lotto[6];
int s[13];
void f(int start, int index){
    if(index == 6){
        for(int i=0; i<6; i++){
            cout << lotto[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=start; i<n;i++){
        lotto[index] = s[i];
        f(i+1, index+1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true){
        cin >> n;
        if(n == 0) break;
        for(int i=0; i<n; i++) cin >> s[i];
        f(0,0);
        cout << endl;
    }
    return 0;
}