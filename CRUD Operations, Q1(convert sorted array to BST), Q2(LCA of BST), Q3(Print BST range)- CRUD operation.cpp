#include<bits/stdc++.h>
using namespace std;

void range(TreeNode * root, const paur<int, int> &rg, vector<int> &result)
{
    if(root == NULL)
        return;
    if(root -> val < rg.first)
    {
        range(root -> right, rg, result);
    }
    else if(root -> val > rg.second)
    {
        range(root-> left, rg, result);
    }
    else{
        result.push_backI(root->val);
        range(root -> left, rg, result);
        range(root-> right, rg, result);
    }
}
vector<int> range(TreeNode *root, pair<int, int> rg){

}

int main()
{
    
}