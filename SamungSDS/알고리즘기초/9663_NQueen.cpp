#include <iostream>

using namespace std;
int n;
int queen[15];
int result = 0;
bool promising(int index){
    for(int i=0; i < index; i++){
        if(queen[index] == queen[i] || abs(queen[i]-queen[index]) == abs(i-index))
            return false;
    }
    return true;
}
void f(int index){
    if(index == n){
        result++;
    }else{
        for(int i=0; i< n; i++){
            queen[index] = i;
            if(promising(index)) f(index+1);
        }
    }   
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    f(0);
    cout << result;
    return 0;
}