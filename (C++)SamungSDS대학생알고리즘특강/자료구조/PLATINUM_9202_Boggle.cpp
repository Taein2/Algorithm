#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 300000
using namespace std;
int w,b;
vector<string> word;
bool found[MAX+1];

char boggle[31][5];
bool visited[31][5];

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,1,-1,0,1,-1};

int max_val=0, max_len=0, find_cnt=0;
// 1글자, 2글자로 이루어진 단어는 0점, 3글자, 4글자는 1점 
// 5글자는 2점, 6글자는 3점, 7글자는 5점, 8글자는 11점
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> w;
    for(int i=0; i<w;i++){
        cin >> word[i];
    }
    cin >> b;
    for(int i=0; i<b; i++){
        for(int j=0; j<4;j++){
            cin >> boggle[i][j];
        }
    }
    // 최대 점수, 가장 긴 단어, 찾은 단어의 개수
    for(int i=0; i < w; i++){
        for(int j=0; j < b; j++){
                          
        }
    }
    return 0;
}