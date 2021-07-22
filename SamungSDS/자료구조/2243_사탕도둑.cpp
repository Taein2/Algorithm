#include <iostream>

using namespace std;
int tree[1000001*4];
long long result = 0;
void update(int node, int left, int right, int index, long long diff){
    // 노드가 관련이 없을 시 
	 if(index<left || index>right) return;
    // 같을 시에 값 갱신
	tree[node] += diff;
    // 단말노드일시
    if (left == right) return;
    // 단말노드가 아닐 시 자식 노드도 변경
	int mid = (left+right)/2;
	update(node * 2 ,left, mid, index, diff);
    update(node * 2 + 1, mid + 1, right, index, diff);
}

long long query(int node, int start, int end, int k){
    if(start == end) return start;
    int mid = (start+end)/2;
    if(k <= tree[2*node]){
        return query(node*2,start,mid,k);
    }else{
        return query(node*2+1,mid+1,end,k - tree[2*node]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a,b,c;
        cin >> a;
        if(a == 2){
            cin >> b >> c;
            update(1,1,1000000,b,c);
        }else{
            cin >> b;
            result = query(1,1,1000000,b);
            cout << result << "\n";
            update(1,1,1000000,result,-1);
        }
    }

    return 0;
}