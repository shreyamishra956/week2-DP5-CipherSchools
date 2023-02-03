#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        
        
        priority_queue<pair<int,int>> q;
        for(auto it : mp)
            q.push({it.second, it.first});
        

        vector<int> vec;
        while(k--)
        {
            pair<int,int> temp = q.top();
            q.pop();
            vec.push_back(temp.second);
        }
        
        return vec;
    }
};


int main()
{

}