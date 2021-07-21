#include <iostream>
#include <deque>
using namespace std;
int arr[5000001];
int n,l;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    deque<pair<int,int>> dq;
    for(int i=0; i<n; i++){
        if(!dq.empty()){
            if(dq.front().second < i - l + 1){
                dq.pop_front();
            } 
        }
        while(!dq.empty() && dq.back().first > arr[i]){
            dq.pop_back();
        }
        dq.push_back(make_pair(arr[i],i));
        cout << dq.front().first << " ";
    }
        
    return 0;
}