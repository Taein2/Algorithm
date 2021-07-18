#include <iostream>
#include <string>
using namespace std;
int n;
int sign[10][10];
int result[10];
bool check(int index){
    int sum = 0;
    for(int i=index; i>=0; i--){
        sum += result[i];
        if(sign[i][index] == 0){
            if(sum != 0 ) return false;
        }else if(sign[i][index] < 0){
            if(sum >= 0) return false;
        }else if(sign[i][index] > 0){
            if(sum <= 0) return false;
        }
    }
    return true;
}
bool f(int index){
    if(index == n) return true;
    if(sign[index][index] == 0){
        result[index] = 0;
        return check(index) && f(index+1);
    }
    for(int i=1; i<=10; i++){
        result[index] = sign[index][index]*i;
        if(check(index) && f(index+1)){
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            if(s[cnt] == '0'){
                sign[i][j] = 0;
            }else if(s[cnt] == '+'){
                sign[i][j] = 1;
            }else{
                sign[i][j] = -1;
            }
            cnt+=1;
        }
    }
    f(0);
    for(int i=0; i<n; i++){
        cout << result[i] << " ";
    }
    return 0;
}