#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;
priority_queue<int> min_heap;
priority_queue<int,vector<int>,greater<int>> max_heap;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        max_heap.push(num); min_heap.push(num);
        if(i%2 == 0){
            //홀수
            cout << "홀수 : ";
            cout << min_heap.top() << "\n";
        }else{
            //짝수
            cout << max_heap.top() << "\n";
            max_heap.pop();
        }
    }

    return 0;
}