#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int l, c;
bool check(string pass){
    int ja = 0;
    int mo = 0;
    for( char ch : pass){
        if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            mo++;
        }else{
            ja++;
        }
    }
    return ja >= 2 && mo >= 1;
}
void f(int index, vector<char> &a, string pass){
    if(l == pass.length()){
        if(check(pass)){
            cout << pass << "\n";
        }
        return;
    }
    if(index == a.size()) return;
    f(index+1, a, pass+a[index]);
    f(index+1, a, pass);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> l >> c;
    vector<char> a(c);
    for(int i=0; i<c; i++){
        cin >> a[i];
    }
    sort(a.begin() ,a.end());
    f(0,a,"");
    return 0;
}