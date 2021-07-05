#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct st{
    string name;
    int kor, eng, math;
};
bool cmp(st a, st b)
{
	if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;
	if (a.kor == b.kor && a.eng == b.eng) return a.math > b.math;
	if (a.kor == b.kor) return a.eng < b.eng;
	return a.kor > b.kor;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<st> v(t);
    for(int i=0; i<t; i++){
        cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i< t; i++) cout << v[i].name << '\n';

    return 0;
}