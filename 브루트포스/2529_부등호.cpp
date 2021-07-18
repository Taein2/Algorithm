#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> result;
char a[20];
int n;
bool check[10];
bool ok(char x , char y, char op){
    if(op == '<'){
        if(x > y) return false;
    }else if(op == '>'){
        if(x < y) return false;
    }
    return true;
}
void f(int index, string num){
    if(index == n+1){
        result.push_back(num);            
        return;
    }
    for (int i=0; i<=9; i++) {
        if (check[i]) continue;
        if(index == 0 || ok(num[index-1],i+'0',a[index-1])){
            check[i] = true;
            f(index+1, num+to_string(i));
            check[i] = false;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    f(0,"");
    auto p = minmax_element(result.begin(), result.end());
    cout << *p.second << "\n";
    cout << *p.first << "\n";
    return 0;
}