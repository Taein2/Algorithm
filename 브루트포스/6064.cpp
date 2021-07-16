#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int M,N,x,y;
        cin >> M >> N >> x >> y;
        x--;    y--;
        bool ok= false;
        // 시간복잡도 O(N) 인 방법으로 푸는 법 x를 고정
        for(int i = x; i< M*N ; i+=M){
            if(i%N==y){
                cout << i+1 << "\n";
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << -1 << "\n";
        }
    }

    return 0;
}