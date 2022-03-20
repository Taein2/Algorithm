#include <iostream>

using namespace std;
long long n,q;
long long tree[100001*4];

void update(int node, int left, int right, int index, long long val){
    if(left == right){
        tree[node] = val;
        return;
    }
	int mid = (left+right)/2;
    if(index <= mid) update(node * 2 ,left, mid, index, val);
    else update(node * 2 + 1, mid + 1, right, index, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}
long long query(int node, int start, int end, int left, int right){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    long long q1 = query(node*2,start,mid,left,right);
    long long q2 = query(node*2+1,mid+1,end,left,right);
    return q1 + q2;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        int num;
        cin >> num;
        update(1,1,n,i,num);
    }
    while(q--){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        if(x>y) swap(x,y);
        cout << query(1,1,n,x,y) << "\n";
		update(1,1,n,a,b);
    }

    return 0;
}