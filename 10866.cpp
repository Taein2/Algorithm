#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    deque<int> dq;
    int t,n;
    string str;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> str;
        if(str == "push_back"){
            cin >> n;
            dq.push_back(n);
        }else if(str == "push_front"){
            cin >> n;
            dq.push_front(n);
        }
        else if(str == "pop_front"){
            if(dq.empty()) cout << -1 << "\n";
            else{
                cout << dq.front() << "\n";
                dq.pop_front();
            } 
        } 
        else if(str == "pop_back"){
            if(dq.empty()) cout << -1 << "\n";
            else{
                cout << dq.back() << "\n";
                dq.pop_back();
            } 
        } 
        else if(str == "size") cout << dq.size() << "\n";
        else if(str == "empty"){
            if(dq.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(str == "front"){
            if(dq.empty()) cout << -1 << "\n";
            else cout << dq.front() << "\n";
        }
        else{
            if(dq.empty()) cout << -1 << "\n";
            else cout << dq.back() << "\n";
        }
    }
    return 0;
}