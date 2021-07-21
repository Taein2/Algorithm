#include <iostream>

using namespace std;
typedef struct node{
    int left; int right;
}node;
node arr[10001];
void postorder(int root){
    if(!root) return;
    postorder(arr[root].left);
    postorder(arr[root].right);
    cout << root << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int root;
    cin >> root;
    int n;
    while(cin >> n){
        int new_root = root;
        while(true){
            if(n > new_root){
                if(!arr[new_root].right){
                    arr[new_root].right = n;
                    break;
                }else{
                    root = arr[new_root].right;
                }
            }
            else{
                if(!arr[new_root].left){
                    arr[new_root].left = n;
                    break;
                }else{
                    new_root = arr[new_root].left;
                }
            }
        }
    }
    postorder(root);
    return 0;
}