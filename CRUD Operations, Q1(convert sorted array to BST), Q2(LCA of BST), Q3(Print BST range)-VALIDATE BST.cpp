#include<bits/stdc++.h>
using namespace std;

bool isValidBST(TreeNode* root) {
        
        return check(root, LONG_MIN, LONG_MAX);
    }

    bool check(TreeNode* root, long minval, long maxval ){

        if(root==NULL) return true;

        if(root->val >= maxval || root->val <= minval) return false;

        return check(root->left,minval, root->val) && check(root->right, root->val, maxval);


    }

int main()
{
    
}