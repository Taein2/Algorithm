#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    queue<int> q;
    int t,n;
    string word;
    int cnt = 0;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> word;
        if(word == "push"){
            cin >> n;
            q.push(n);
        }
        else if(word == "pop"){
            if(!q.empty()){
                cout << q.front() << "\n";
                q.pop();
            } 
            else cout << -1 << "\n";
        }else if(word == "size"){
            cout << q.size() << "\n";
        }else if(word == "empty"){
            if(!q.empty()) cout << 0 << "\n";
            else cout << 1 << "\n";
        }else if(word == "front"){
            if(!q.empty()) cout << q.front() << "\n";
            else cout << -1 << "\n";
        }else{
            if(!q.empty()) cout << q.back() << "\n";
            else cout << -1 << "\n";
        }
    } 
    return 0;
}