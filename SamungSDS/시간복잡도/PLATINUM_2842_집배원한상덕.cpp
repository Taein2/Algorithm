#include <iostream>
#include <vector>

using namespace std;
char map[51][51];
int num[51][51];
int n;
int dx[8] = {1,1,1,0,1,0,0,0};
int dy[8] = {0,1,-1,1,0,0,1,-1};
int result = 0;
void f(int x, int y){
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> num[i][j];
        }
    }
    f(0,0);
    cout << result;
    return 0;
}