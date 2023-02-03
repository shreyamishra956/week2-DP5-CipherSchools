#include<bits/stdc++.h>
using namespace std;


int find (vector<int> &preoder, int start, int end, int x)
{
    int tndex = start;
    while(index <= end && preorder[index] > x)
    {
        index++;
    }

    return index;
}

TreeNode* bildTree(vector<int> &preorder, int start, int end)
{
    if(start > end)
        return NULL;
    
    TreeNode* newNode = new TreeNode(preorder[start]);
    if(start == end)
        return newNode;
    else{
        int index = find(preorder, start + 1, end, newNode-> val);
        newNode-> left = buildTree(preorder, start +1, index -1);
        newNode-> right = buildTree(preorder, index, end);
        return newNode;
    }
}