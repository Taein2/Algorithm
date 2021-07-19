#include <iostream>
using namespace std;

int arr[10001];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }    
    int low = 0, high = 0;
    int sum = arr[0];
    int result = 0;
    while(low <= high && high <n){
        if(sum < m){
            sum += arr[++high];
        }else if(sum == m){
            result++;
            sum += arr[++high];
        }else{
            sum -= arr[low++];
            if(low > high && low < n){
                high = low;
                sum = arr[low];
            }
        }
    }
    cout << result;
    return 0;
}