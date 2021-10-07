#include <iostream>
#include <vector>

using namespace std;

int t;
int order[101];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    int num;
    for(int i=1; i<101; i++){
        order[i] = i;
    }
    int tmp;
    for (int i=1; i<=t; i++){
        cin >> num;
        if (num > 0){
            tmp = order[i];
            for (int j=i; j>i-num; j--){
                order[j] = order[j-1];
            }
            order[i-num] = tmp;
        }
    }
    for (int i=1; i<=t; i++){
        cout << order[i] << " ";
    }
    return 0;
}