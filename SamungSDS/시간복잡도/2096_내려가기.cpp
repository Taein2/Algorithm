#include <iostream>

using namespace std;
int n;
int map[100001][3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0; j<3; j++){
            cin >> map[i][j];
        }
    }
    

    return 0;
}