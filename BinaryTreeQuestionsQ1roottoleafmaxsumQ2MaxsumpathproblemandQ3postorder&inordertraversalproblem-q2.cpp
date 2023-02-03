#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int maxpath = INT_MIN;
    int sumpath(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        if(root -> left == NULL && root -> right == NULL)
        {
            maxpath = max(maxpath, root-> val);
            return root -> val;
        }
        
        int l = sumpath(root -> left);
        int r = sumpath(root -> right);
        
        
        maxpath = max(maxpath, max(root -> val, max(r + root-> val + l, max(r+root->val, l+root->val))));
        
        return max(root -> val, max(l+ root-> val, r + root-> val));
    }
    
    int maxPathSum(TreeNode* root) 
    {
        if(root -> left == NULL && root -> right == NULL)
            return root->val;
        sumpath(root);
        return maxpath;
    }
};


int main()
{

    
}