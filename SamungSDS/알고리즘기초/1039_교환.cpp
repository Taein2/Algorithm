#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;
string n;
int k,result = 0;
int calculator(string str){
    int sum = 0;
    for(int i=0; i<str.length(); i++){
        sum *= 10;
        sum += str[i] - '0';
    }
    return sum;
}
void bfs(string str){
    queue<string> q;
    q.push(str);
    int length = str.length();
    int cnt = 0; // 바꾼 횟수

    while(cnt < k){
        int qs = q.size();
        set<string> visit;
        for(int i=0; i<qs; i++){
            string now = q.front();
            q.pop();
            for(int i=0; i < length-1; i++){
                for(int j=i+1; j < length; j++){
                    if(i == 0 && now[j] == '0') continue;
                    swap(now[i],now[j]);
                    if(!visit.count(now)){
                        if(cnt == k-1 && result != calculator(now)){
                            result = max(result, calculator(now));
                        }
                        q.push(now);
                        visit.insert(now);
                    }
                    swap(now[i],now[j]);
                }                
            }
        }
        cnt++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    if(n.length() == 1 || (n.length() == 2 && calculator(n) % 10 == 0)){
        cout << -1;
        return 0;
    }
    bfs(n);
    cout << result;
   
    return 0;
}