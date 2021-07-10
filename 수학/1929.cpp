#include <iostream>

using namespace std;
const int MAX = 1000000;
bool ck[MAX+1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ck[0] = ck[1] = true;
    for(int i=2; i*i <= MAX; i++){
        if(ck[i] == false){
            for(int j=i+i; j <= MAX; j+=i)
                ck[j] = true;
        }   
    }
    int a,b;
    cin >> a >> b;
    for(int i=a; i<=b; i++){
        if(ck[i] == false){
            cout << i << "\n";
        }
    }
    return 0;
}