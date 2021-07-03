#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,num=0;
    queue<int> q;
    cin >> n >> k;
    for (int i=1; i<n+1; i++){
        q.push(i);
    }
    cout << "<";
    while(q.size() != 1){
        for(int i=1; i<k; i++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";
    return 0;
}