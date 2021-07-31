#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<pair<int,int>> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++){
        int y, r;
        cin >> y >> r;
        v.push_back(make_pair(y,r));
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int y,x;
        // y년도 x년도 그리고 그 사이 모든 년도들의 강수량에 대한 정보가 있음
        // x년도 강수량은 y년도 강수량 이하
        // y < z < x 를 만족하는 모든 z에 대해 z년도 강수량은 x년도보다 적음
        // 1번 만족안하면 가능maybe
        cin >> y >> x;
        int diff = x - y + 1;
        int cnt = 0; // 1번 조건
        int max_r = -1; //3번 조건
        int y_r, x_r; // 2번 조건
        //존재하는지 체크
        bool exist_x = false;
        bool exist_y = false;
        for(int i=0; i < v.size(); i++){
            if(v[i].first < y){
               continue; 
            }else if(v[i].first == y){
                cnt++;
                y_r = v[i].second;
                exist_y = true;
            }else if(v[i].first > y && v[i].first < x){
                cnt++;
                int tmp = v[i].second;
                max_r = max(tmp, max_r);
            }else if(v[i].first == x){ // x와 같을때
                cnt++;
                x_r = v[i].second;
                exist_x = true;
            }
            if(i == v.size()-1){
                if(x_r <= y_r && max_r < x_r){
                    if(cnt == diff){
                        cout << "true" << "\n";
                    }else{
                         cout << "maybe" << "\n";
                    }
                }else{
                    cout << "false" << "\n";
                }
            }
        }
    }

    return 0;
}
