#include<bits/stdc++.h>
using namespace std;


int chk(TreeNode* root){
    if(root==NULL){return 0;}
    int l=chk(root->left);
    int r=chk(root->right);
    if(l==-1 || r==-1){return -1;}
    if(abs(l-r)>1){return -1;}
    return 1+max(l, r);
}
bool isBalanced(TreeNode* root) {
    return chk(root)!=-1;
}

int main()
{
    
}