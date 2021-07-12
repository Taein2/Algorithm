#include <iostream>

using namespace std;
bool broken[10];
int possible(int c){
    if(c == 0){
        if(broken[0]){
            return 0;
        }else{
            return 1;
        }
    }
    int len = 0;
    while( c > 0){
        if (broken[c%10]){
            return 0;
        }
        len +=1;
        c/=10;
    }
    return len;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /* 숫자 -> 버튼( +, - 중 하나) */
    /* 이동할 채널에 고장난 버튼이 있는지 확인 */
    int channel, t;
    int first = 100;
    cin >> channel;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        broken[n] = true;
    }
    int result = channel - 100;
    if (result < 0){
        result = -result;
    }
    for(int i=0; i<= 1000000; i++){
        int len = possible(i);
        if (len > 0){
            int press = i - channel;
            if(press <0){
                press = -press;
            }
            if( result > len + press){
                result = len + press;
            }
        }
    }
    cout << result;
    return 0;
}