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
    int j;
    for(int i=0; i<v.size()-1;i++){ // 삽입정렬도 O(n^2) 이지만 가장 우수 , 거의 정렬되어있는경우 가장 빠름 아닐시 넘어가기때문
        j = i;
        while(v[j] > v[j+1]){
            tmp = v[j];
            v[j] = v[j+1];
            v[j+1] = tmp;
            j--;
        }
    }
    for(int i=0; i< v.size(); i++)
        cout << v[i] << " ";       

    return 0;
}