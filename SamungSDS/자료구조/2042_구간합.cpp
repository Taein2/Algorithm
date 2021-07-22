#include <iostream>
#include <cmath>
using namespace std;
int n,m,k;
int a,b;
long long c;
long long arr[1000001];
long long tree[1000001*4];
long long init(int node, int left, int right){
    // 단말노드이면
    if(left == right) return tree[node] = arr[left];
    // 단말노드가 아닐시
    int mid = (left+right)/2;
    // 왼쪽 자식과 오른쪽 자식 노드의 합
    return tree[node] = init(node * 2,left,mid) + init(node*2 + 1,mid+1,right);
}
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

long long query(int node, int start, int end, int left, int right){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return query(node*2,start,mid,left,right) + query(node*2+1,mid+1,end,left,right);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    init(1,0,n-1);
    
    for(int i=0;i<m+k;i++){
        cin>>a>>b>>c;
        if(a==1){   //b->c로 변환
            long long diff = c-arr[b-1];
            arr[b-1]=c;
            update(1,0,n-1,b-1,diff);
        }
        else if(a==2)      //b~c합
            cout << query(1,0,n-1,b-1,c-1)<<'\n';
    }
    return 0;
}