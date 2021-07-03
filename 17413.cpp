#include <iostream>
#include <deque>
#include <string>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    deque<char> dq;
    bool flag = true;
    getline(cin,str);
    for(int i=0; i < str.length(); i++){
        if(str[i] == ' ' && flag ){
            while(!dq.empty()){
                cout << dq.back();
                dq.pop_back();
            }
            cout << " ";
        }
        else if(str[i] == '<'){
            while(!dq.empty()){
                cout << dq.back();
                dq.pop_back();
            }
            flag = false;
        } 
        else if(str[i] == '>'){
            cout << "<";
            while(!dq.empty()){
                cout << dq.front();
                dq.pop_front();
            }
            cout << ">";
            flag = true;
        }else{
            dq.push_back(str[i]);
        } 
        
    }
    while(!dq.empty()){
        cout << dq.back();
        dq.pop_back();
    }
    return 0;
}