#include <iostream>
#include <algorithm>
#define MAX_SIZE 10001
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n;
    int arr[MAX_SIZE] ={0};
    cin >> t;
    for(int i=0; i< t; i++){
        cin >> n;
        arr[n]+= 1;
    }
    for(int i=0; i< MAX_SIZE; i++){
        for(int j=0; j< arr[i];j++){
            cout << i << "\n";
        }
    }
    
    return 0;
}