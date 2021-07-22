#include <iostream>

using namespace std;
typedef struct node{
    int left = 0; 
    int right = 0;
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
        int current_node = root;
        while(1){
            if(n < current_node){
                if(arr[current_node].left != 0){
                    current_node = arr[current_node].left;
                }else{
                    arr[current_node].left = n;
                    break;
                }
            }
            else{
                if(arr[current_node].right != 0){
                    root = arr[current_node].right;
                }else{
                    arr[current_node].right = n;
                    break;
                }
            }

        }
    }
    postorder(root);
    return 0;
}