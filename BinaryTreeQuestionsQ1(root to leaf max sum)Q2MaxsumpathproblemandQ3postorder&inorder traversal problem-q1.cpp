#include<bits/stdc++.h>
using namespace std;

void maxSumPath(TreeNode* root, int sum, int &maxsum)
{
    if(root == NULL)
        return ;
    
    sum += root -> val;

    if(root != NULL && root -> left == NULL && root -> right == NULL)
    {
        maxsum = max(sum, maxsum);
        return;
    }

    else
    {
        maxSumPath(root -> left, sum, maxsum);
        maxSumPath(root -> left, sum, maxsum);
    }
}

int pathsum(TreeNode* root)
{
    int maxsum = 0;
    maxSumPath(root, 0, maxsum);
    return maxsum;
}

int main()
{
    
}