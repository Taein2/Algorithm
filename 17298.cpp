#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    stack<int> st;
    vector<int> v;
    cin >> t;
    for(int i=0; i< t; i++){
        cin >> n;
        v.push_back(n);
    }
    vector<int> result(t,-1);
    for(int i=0; i< v.size(); i++){
        while(!st.empty() && v[st.top()] < v[i]){
            result[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }    
    for(int x : result) cout << x << " ";
    return 0;
}