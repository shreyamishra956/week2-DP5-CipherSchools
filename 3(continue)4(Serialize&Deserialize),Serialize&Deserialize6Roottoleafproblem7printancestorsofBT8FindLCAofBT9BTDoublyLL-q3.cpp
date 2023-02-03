#include<bits/stdc++.h>
using namespace std;


bool isLeaf(TreeNode* root)
{
    if(root != NULL &&& root -> left == NULL && root -> right == NULL)
        return true;
    return false;
}

void populatedRandomPointer(TreeNode * root)
{
    if(root == NULL || isLeaf(root))
    {
        return;
    }

    queue<TreeNode*> Q;

    Q.push(root);
    TreeNode* prev;
    while(!Q.empty())
    {
        int size = Q.size();
        for(int i = 0; i < size; i++)
        {
            root= Q.top();
            Q.pop();
            if(i == 0)
            {
                prev = root;
            }

            else{
                prev->random = root;
                prev = root;
            }
            if(root -> left )
            {
                Q.push(root->left);
            }

            if(root->right)
            {
                Q.push(root->right);
            }
        }
    }

}

int main()
{

}