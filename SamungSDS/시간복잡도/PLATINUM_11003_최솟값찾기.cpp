#include <iostream>
#include <deque>
#define MAX 5000000
using namespace std;
int arr[MAX+1];
int n,l;
deque<pair<int,int>> dq;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        if(!dq.empty() && dq.front().second < i - l + 1){
                dq.pop_front();
        }
        while(!dq.empty() && dq.back().first > arr[i]){
            dq.pop_back();
        }
        dq.push_back(make_pair(arr[i],i));
        cout << dq.front().first << " ";
    }
        
    return 0;
}