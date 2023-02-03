#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> vec;
void traversal(Node* root, vector<int> v)
{
    if(root != NULL && root -> left == NULL && root -> right == NULL)
    {
        v.push_back(root->data);
        vec.push_back(v);
        return;
    }
    
    v.push_back(root->data);
    if(root -> left != NULL)
    traversal(root->left, v);
    if(root -> right != NULL)
    traversal(root->right, v);
}

 
 
 
vector<vector<int>> Paths(Node* root)
{
    vector<int> v;
    traversal(root, v);
    return vec;
}

int main()
{

}