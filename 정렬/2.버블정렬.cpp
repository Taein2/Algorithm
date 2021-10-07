#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int tmp;
int main(){             
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    while(cin >> num){
        if(num == 0)
            break;
        v.push_back(num);
    }

    for(int i=0; i<v.size();i++){
        for(int j=0; j<v.size() - i;j++){ // 비교 연산 횟수 n + n-1 + n-2 + n-3 ..... + 1 = n * (n-1) / 2  ~= O(n^2)
            if(v[j] > v[j+1]){          // 버블정렬은 당장 옆에 있는것과 자리 비교연산이기에 선택정렬보다 느림
                tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
    for(int i=0; i< v.size(); i++)
        cout << v[i] << " ";       

    return 0;
}