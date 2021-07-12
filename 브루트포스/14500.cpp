#include <iostream>
// 총 19가지 방법 N * M  -> O(NM)
using namespace std;
int a[500][500];
int block[19][3][2] = {
    {{0,1}, {0,2}, {0,3}},
    {{1,0}, {2,0}, {3,0}},
    {{1,0}, {1,1}, {1,2}},
    {{0,1}, {1,0}, {2,0}},
    {{0,1}, {0,2}, {1,2}},
    {{1,0}, {2,0}, {2,-1}},
    {{0,1}, {0,2}, {-1,2}},
    {{1,0}, {2,0}, {2,1}},
    {{0,1}, {0,2}, {1,0}},
    {{0,1}, {1,1}, {2,1}},
    {{0,1}, {1,0}, {1,1}},
    {{0,1}, {-1,1}, {-1,2}},
    {{1,0}, {1,1}, {2,1}},
    {{0,1}, {1,1}, {1,2}},
    {{1,0}, {1,-1}, {2,-1}},
    {{0,1}, {0,2}, {-1,1}},
    {{0,1}, {0,2}, {1,1}},
    {{1,0}, {2,0}, {1,1}},
    {{1,0}, {2,0}, {1,-1}}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    int result = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<19; k++){
                bool ok = true;
                int sum = a[i][j];
                for(int l =0; l < 3; l++){
                    int x = i + block[k][l][0];
                    int y = j + block[k][l][1];
                    if( x >= 0 && x < n && y < m && y >= 0){
                        sum += a[x][y];
                    }else{
                        ok = false;
                        break;
                    }
                }
                if( ok && result < sum) result = sum;
            }
        }
    }
    cout << result;
    return 0;
}
