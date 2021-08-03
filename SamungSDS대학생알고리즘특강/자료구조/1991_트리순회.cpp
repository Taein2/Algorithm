#include <iostream>

using namespace std;
typedef struct node{
    char left;
    char right;
}node;
node arr[27];
int n;
void preorder(char root){
    if(root == '.') return;
    cout << root;
    preorder(arr[root].left);
    preorder(arr[root].right);
}
void inorder(char root){
    if(root == '.') return;
    inorder(arr[root].left);
    cout << root;
    inorder(arr[root].right);
}
void postorder(char root){
    if(root == '.') return;
    postorder(arr[root].left);
    postorder(arr[root].right);
    cout << root;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++){
        char a,b,c;
        cin >> a >> b >> c;
        arr[a].left = b;
        arr[a].right = c;
    }
    char root = 'A';
    preorder(root); 
    cout << "\n";
    inorder(root);
    cout << "\n";
    postorder(root);
    return 0;
}