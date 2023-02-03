#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int preindex = 0;
    TreeNode* tree(vector<int> pre,vector<int> in,int is,int ie, unordered_map<int, int> &h)
    {
        if(is > ie) return NULL;
        TreeNode *root = new TreeNode(pre[preindex++]);
        int inIndex = (h.find(root->val)) -> second;
        
        root -> left = tree(pre, in, is, inIndex - 1, h);
        root -> right = tree(pre, in, inIndex + 1, ie, h);
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> h;
        for (int i = 0; i < inorder.size(); i++)
        {
            h[inorder[i]] = i;
        }
        TreeNode *ans = tree(preorder, inorder, 0, inorder.size()-1, h);
        return ans;
    }
};



int main()
{

}