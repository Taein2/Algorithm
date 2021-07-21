#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    queue<int> q;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        if(str == "push"){
            int num;
            cin >> num;
            q.push(num);
        }else if(str == "pop"){
            if(q.size()){
                cout << q.front() << "\n";
                q.pop();
            }else cout << -1 << "\n";
        }else if(str == "size"){
            cout << q.size() << "\n";
        }else if(str == "empty"){
            if(q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }else if(str == "front"){
            if(q.size()){
                cout << q.front() << "\n";
            }else cout << -1 << "\n";
        }else if(str == "back"){
            if(q.size()){
                cout << q.back() << "\n";
            }else cout << -1 << "\n";    
        }
    }

    return 0;
}