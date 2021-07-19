#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX 1000000000
using namespace std;

stack<long long> s;
vector<string> v;
vector<long long> num;
bool NUM(long long number){
    s.push(number);
    return false;
}
bool POP(){
    if(s.empty()){
        return true;
    }
    s.pop();
    return false;
}
bool INV(){
    if(s.empty()){
        return true;
    }
    long long tmp = s.top();
    s.pop();
    tmp = tmp * -1;
    s.push(tmp);
    return false;
}
bool DUP(){
    if(s.empty()){
        return true;
    }
    long long tmp = s.top();
    s.push(tmp);
    return false;
}
bool SWP(){
    if(s.size() < 2){
        return true;
    }
    long long tmp1 = s.top();
    s.pop();
    long long tmp2 = s.top();
    s.pop();
    s.push(tmp1); s.push(tmp2);
    return false;
}
bool ADD(){
    if(s.empty()){
        return true;
    }
    long long tmp = s.top();
    s.pop();
    if(s.empty()){
        return true;
    }
    tmp += s.top();
    s.pop();
    s.push(tmp);
    return false;
}
bool SUB(){
    if(s.empty()){
        return true;
    }
    long long tmp = s.top();
    s.pop();
    if(s.empty()){
        return true;
    }
    tmp = s.top() - tmp;
    s.pop();
    s.push(tmp);
    return false;
}
bool MUL(){
    if(s.size() < 2){
        return true;
    }
    long long tmp = s.top();
    s.pop();
    tmp *= s.top();
    s.pop();
    s.push(tmp);
    return false;
}
/*
bool DIV(){
    if(s.size() < 2){
        return true;
    }
    bool flag = false;
    if(s.top() < 0) flag = true;
    long long tmp1 = s.top();
    s.pop();
    if(s.top() < 0) flag = true; 
    if(tmp1 == 0) return true;     
    long long tmp2 = s.top();
    s.pop();
    long long result = tmp2 / tmp1;
    if(flag){
        result = -(abs(result));
    }else{
        result = abs(result);
    }
    s.push(result);
    return false;
}
bool MOD(){
    if(s.size() < 2){
        return true;
    }
    bool flag = false;
    long long tmp1 = s.top();
    s.pop();
    if(s.top() < 0) flag = true; 
    long long tmp2 = s.top();
    if(tmp1 == 0) return true; 
    s.pop();
    long long result = tmp2 % tmp1;
    if(flag){
        result = -(abs(result));
    }else{
        result = abs(result);
    }
    s.push(result);
    return false;
}

*/
 
int DIV()
{
	int neg = 0;
 
	if (s.empty()) {
		return 1;
	}
 
	long long x = s.top();
 
	if (x < 0) {
		++neg;
	}
 
	s.pop();
 
	if (s.empty()) {
		return 1;
	}
 
	long long y = s.top();
 
	if (y < 0) {
		++neg;
	}
 
	if (x == 0) {
		return 1;
	}
 
	x = y / x;
	if (neg == 1) {
		x = -(abs(x));
	}
	else {
		x = abs(x);
	}
 
	s.pop();
	s.push(x);
 
	return 0;
}
 
int MOD()
{
	int neg = 0;
 
	if (s.empty()) {
		return 1;
	}
 
	long long x = s.top();
 
	s.pop();
 
	if (s.empty()) {
		return 1;
	}
 
	long long y = s.top();
 
	if (y < 0) {
		++neg;
	}
 
	if (x == 0) {
		return 1;
	}
 
	x = y % x;
	if (neg == 1) {
		x = -(abs(x));
	}
	else {
		x = abs(x);
	}
 
	s.pop();
	s.push(x);
 
	return 0;
}
 


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    long long x;
    int n;
    while(1){
        while (1) {
			cin >> str;
			if (str == "NUM") {
				cin >> x;
				num.push_back(x);
			}
			if (str == "QUIT") {
				return 0;
			}
			if (str == "END") {
				break;
			}
			v.push_back(str);
		}   
        bool err = false;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> x;
            s.push(x);
            int index = 0;
            for(int i=0; i < v.size(); ++i){
                if(v[i] == "NUM"){
                    err = NUM(num[index]);
                    ++index;
                }else if(v[i] == "POP"){
                    err = POP();
                }else if(v[i] == "INV"){
                    err = INV();
                }else if(v[i] == "DUP"){
                    err = DUP();
                }else if(v[i] == "SWP"){
                    err = SWP();
                }else if(v[i] == "ADD"){
                    err = ADD();
                }else if(v[i] == "SUB"){
                    err = SUB();
                }else if(v[i] == "MUL"){
                    err = MUL();
                }else if(v[i] == "DIV"){
                    err = DIV();
                }else if(v[i] == "MOD"){
                    err = MOD();
                }
                if(!s.empty() && (s.top() > MAX || s.top() < -MAX)) err = true;
                if(err){
                    break;
                }                
            }
            if(err || s.size() != 1){
                cout << "ERROR" << "\n";
            }else{
                cout << s.top() << "\n";
            }
            while(!s.empty()) s.pop();
        }
        num.clear();
        v.clear();
        cout << "\n";
    }

    return 0;
}