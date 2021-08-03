#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> s;
long long result = 0;
int num = 1;
bool possible = true;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string bracket;
    cin >> bracket;
    for(int i=0; i<bracket.length(); i++){
        if(bracket[i] == '('){
            num *= 2;
            s.push('(');
        }else if(bracket[i] == '['){
            num *= 3;
            s.push('[');
        }else if(bracket[i] == ')' && (s.empty() || s.top() != '(')){
            possible = false;
            break;
        }else if (bracket[i] == ']' && (s.empty() || s.top() != '[')){
            possible = false;
            break;
        }else if(bracket[i] == ')'){
            if(bracket[i-1] == '(') result += num;
            s.pop();
            num /= 2;
        }else if(bracket[i] == ']'){
            if(bracket[i-1] == '[') result += num;
            s.pop();
            num /= 3;
        }
    }
    if(!possible || !s.empty()){
        cout << 0;
    }else{
        cout << result;
    }
    return 0;
}