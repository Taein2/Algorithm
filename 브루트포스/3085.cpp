#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int check(vector<string> &v,int t){
    int result = 1;
    for(int i=0; i< t; i++){
        int cnt = 1;
        for(int j=1; j<t; j++){
            if ( v[i][j] == v[i][j-1]) cnt++;
            else cnt = 1;
            if (result < cnt) result = cnt;
        }
        cnt = 1;
        for(int j=1; j<t; j++){
            if ( v[j][i] == v[j-1][i]) cnt++;
            else cnt = 1;
            if( result < cnt) result = cnt;
        }
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<string> v(t);
    for (int i=0; i<t; i++){
        cin >> v[i];
    }
    // 오른쪽, 아래쪽 구현
    int result = 0;
    for(int i=0; i< t; i++){
        for (int j=0; j <t; j++){
            if (j+1 < t){
                swap(v[i][j], v[i][j+1]);
                int temp = check(v,t);
                if(result < temp ) result = temp;
                swap(v[i][j], v[i][j+1]);
            }
            if(i+1 < t){
                swap(v[i][j], v[i+1][j]);
                int temp = check(v,t);
                if(result < temp ) result = temp;
                swap(v[i][j], v[i+1][j]);   
            }
        }
    }
    
    cout << result;

    return 0;
}