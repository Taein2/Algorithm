#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    list<char> l;
    string str;
    cin >> str;
    for( int i =0; i< str.length(); i++){
        l.push_back(str[i]);
    }
    auto idx = l.end();
    int n = 0;
    char x, y;
    cin >> n;
    for (int i=0; i< n; i++){
        cin >> x;
        if (x == 'P'){
            cin >> y;
            l.insert(idx, y);
        }else if(x == 'L' && idx != l.begin()){
            idx--;
        }else if(x == 'D' && idx != l.end()){
            idx++;
        }else if(x == 'B' && idx != l.begin()){
            idx--;
            idx = l.erase(idx);
        }
    }
    for (auto idx:l){
        cout << idx;
    }
    return 0;
}