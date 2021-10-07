#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
void quickSort(int start, int end){
    if(start >= end){ // 원소가 한개인 경우
        return;
    }
    int key = start;
    int i = start+1; int j = end;  
    while(i <= j){
        while(i <= end && v[i] <= v[key]) i++; // key 값보다 큰 값을 만날 때까지 
        while(j > start && v[j] >= v[key]) j--; // key 값보다 작은 값을 만날 때까지
        if(i > j){
            int tmp = v[key];
            v[key] = v[j];
            v[j] = tmp;
        }else{
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
        }
    }
    quickSort(start+1, end);
    quickSort(start, end-1);
}
int main(){             
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    while(cin >> num){
        if(num == 0)
            break;
        v.push_back(num);
    }
    // O(n * log n) 데이터가 10만개 이상이 되어도 사용할 수 있도록 but 최악의 경우 O(n^2) -> 이미 정렬되어 있는 경우
    quickSort(0,v.size());
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    return 0;
}