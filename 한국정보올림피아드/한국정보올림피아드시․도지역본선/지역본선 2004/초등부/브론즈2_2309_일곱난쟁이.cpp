#include <iostream>
#include <algorithm>

using namespace std;
  
int arr[9];
int sum;
int cnt;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sum = 0;
    cnt = 0;
    for (int i=0; i<9; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr+9);
    for (int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if (sum - arr[i] - arr[j] == 100){
                for (int k=0; k<9; k++){
                    if (k != i && k != j){
                        cout << arr[k];
                        cnt++;
                        if(cnt != 7)
                            cout << "\n";
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}