#include <iostream>
#include <vector>
using namespace std;

//선택 정렬
int min_num = 987654321;
int index ,tmp;
vector<int> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    while(cin >> num){
        if(num == 0)
            break;
        v.push_back(num);
    }
    for(int i=0; i < v.size(); i++){
        min_num = 987654321;
        for(int j=i; j< v.size(); j++){ // 비교 연산 횟수 n + n-1 + n-2 + n-3 ..... + 1 = n * (n-1) / 2  ~= O(n^2)
            if(min_num > v[j]){
                min_num = v[j];
                index = j;
            }
        }
        tmp = v[i];
        v[i] = min_num;
        v[index] = tmp;
    }
    for(int i=0; i< v.size(); i++)
        cout << v[i] << " ";       
    return 0;
}