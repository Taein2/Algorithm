#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int t;
    string sentence;
    stack <char> st;
    cin >> t;
    cin.ignore();
    for(int i=0; i<t; i++){
        getline(cin,sentence);
        sentence += ' ';
        for( int i =0; i < sentence.size(); i++){
            if(sentence[i] == ' '){
                while(!st.empty()){
                    cout<< st.top();
                    st.pop();
                }cout <<' ';
            }else
                st.push(sentence[i]);
        }cout << '\n';
    }
    return 0;
}