#include <iostream>

using namespace std;
bool c[10];
int a[10];
void f(int index,int start, int n, int m){
    if (index == m){
        for(int i=0; i<m; i++){
            cout << a[i];
            if(i != m-1) cout << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=start; i<=n ; i++){
        if(c[i]) continue;
        else{
            c[i] = true; a[index] = i;
            f(index+1,i+1, n, m);
            c[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    f(0,1,n,m);   

    return 0;
}