#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    void traversal (TreeNode* root, vector<int> &vec)
    {
        if(root == NULL)
            return;
        vec.push_back(root->val);
        traversal(root->left, vec);
        traversal(root->right, vec);
    }       
    
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        traversal(root, vec);
        return vec;
    }




    void inorder (TreeNode* root, vector<int> &vec)
    {
        if(root == NULL) return;
        inorder(root -> left, vec);
        vec.push_back(root-> val);
        inorder(root -> right, vec);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        inorder(root , vec);
        return vec;
    }



    void traversal(TreeNode* root,vector<int> &vec)
    {
        if(root == NULL)
        {
            return ;
        }
        traversal(root -> left,vec);
        traversal(root -> right,vec);
        vec.push_back(root -> val);
        
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        traversal(root,vec);
        return vec;
    }


    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(root == NULL) return vec;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        
        while(q.size() > 1)
        {
            int size = q.size();
            vector<int> temp;
            for(int i = 1; i < size; i++)
            {
                TreeNode* ans = q.front();
                q.pop();
                temp.push_back(ans -> val);
                if(ans -> left != NULL)
                {
                    q.push(ans -> left);
                }
                if(ans -> right != NULL)
                {
                    q.push(ans -> right);
                }
            }
            q.pop();
            q.push(NULL);
            vec.push_back(temp);
        }
        return vec;
    }





    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        
        priority_queue<int, vector<int>, cmp>
        map< int, map<int, priority_queue<int, vector<int>, greater<int>> > > mp;
        
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            pair<TreeNode*,pair<int,int>> temp = q.front();
            q.pop();
            
            int v = temp.second.first;
            int h = temp.second.second;
            
            mp[v][h].push(temp.first->val);
            if(temp.first -> left != NULL)
            {
                q.push({temp.first->left,{v-1, h+ 1}});
            }
            if(temp.first -> right != NULL)
            {
                q.push({temp.first->right,{v+1, h+1}});
            }
        }
        
        vector<vector<int>> v;
        
        for(auto it : mp)
        {
            vector<int> temp;
            for(auto i : it.second)
            {
                while(!i.second.empty())
                {
                    temp.push_back(i.second.top());
                    i.second.pop();
                }
            }
            v.push_back(temp);
        }
        return v;
    }


    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(root == NULL) return vec;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        
        s1.push(root);
        while(s1.empty() == false || s2.empty() == false)
        {
            vector<int> temp;
            if(s1.empty() == false)
            {
                int size = s1.size();
                for(int i = 0; i< size; i++)
                {
                    TreeNode *curr = s1.top();
                    s1.pop();
                    temp.push_back(curr -> val);
                    if(curr -> left != NULL) s2.push(curr -> left);
                    if(curr -> right != NULL) s2.push(curr -> right);
                }
            }
            else
            {
                int size = s2.size();
                for(int i = 0; i< size; i++)
                {
                    TreeNode *curr = s2.top();
                    s2.pop();
                    temp.push_back(curr -> val);
                    if(curr -> right != NULL) s1.push(curr -> right);
                    if(curr -> left != NULL) s1.push(curr -> left);
                }
            }
            vec.push_back(temp);
        }
        return vec;
    }


};




class Solution {
public:
    int res = 0;
    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int l = height(root -> left);
        int r = height(root -> right);
        
        res = max(res, 1+l+r);
        return 1 + max(l,r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        height(root);
        return res;
    }
};










int main()
{

}