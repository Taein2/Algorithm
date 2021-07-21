#include <iostream>
#include <queue>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<int> pq;

    for(int i=0; i<n; i++){
        long long num;
        cin >> num;
        if(num == 0 && pq.empty()){
            cout << 0 << "\n";
        }else if(num == 0 && !pq.empty()){
            cout << pq.top() << "\n";
            pq.pop();
        }else{
            pq.push(num);
        }
    }
    return 0;
}