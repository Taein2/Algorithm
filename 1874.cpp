#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int t, n;
	stack<int> s;
	vector<int> sol; 
    vector<char> v;
	cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        sol.push_back(n);
    }
    int idx = 0;
    for(int i=1 ; i<= t; i++){
        s.push(i);
        v.push_back('+');

        while(!s.empty()){
            if(sol[idx] == s.top()){
                s.pop();
                v.push_back('-');
                idx++;
            }
            else break;
        }
    }
    if(s.empty()){
        for(int i = 0; i < v.size(); i++){   
            cout << v[i] << "\n";
        }
    }else{
        cout << "NO" << "\n";
    }
    return 0;
}