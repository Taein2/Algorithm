#include <iostream>
#include <string>

using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    string str1,str2;
    str1 = (to_string)(a) + (to_string)(b);
    str2 = (to_string)(c) + (to_string)(d);
    long long result = (stoll)(str1)+(stoll)(str2);
    cout << result;
    return 0;
}