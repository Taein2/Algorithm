#include <iostream>
#include <string>

using namespace std;
int N,K;
string word[55];
int alphabet[26];
int result = 0;
int count(){
    int wordCnt = 0;
    for(int i = 1; i <= N; i++){
        bool flag = true;
        for(int j = 0; j < word[i].size(); j++){
            if(alphabet[word[i][j]-'a'] == 0){
                flag = false;
                break;
            }
        }
        if(flag == true) wordCnt++;
    }    
    return wordCnt;
}
void f(int idx, int cnt){  
    if(cnt == K-5){
        result = max(result, count());
        return;
    }
    for(int i = idx; i < 26; i++){
        if(alphabet[i] == 1) continue;   
        alphabet[i] = 1;
        f(i+1, cnt+1);
        alphabet[i] = 0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    if(K <= 4){
        for(int i = 1; i <= N; i++){
            cin >> word[i];
        }        
        cout << "0";
    }
    else{
        alphabet['a'-'a'] = 1;
        alphabet['c'-'a'] = 1;
        alphabet['i'-'a'] = 1;
        alphabet['n'-'a'] = 1;
        alphabet['t'-'a'] = 1;
        
        for(int i = 1; i <= N; i++){
            cin >> word[i];
        }
        f(0,0);
        cout << result;  
    }
    return 0;
}