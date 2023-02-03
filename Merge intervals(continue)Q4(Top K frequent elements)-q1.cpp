#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) 
    {
        
        sort(v.begin(), v.end());
        vector<vector<int>> vec;
        vec.push_back(v[0]);
        int count = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(vec[count][1] >= v[i][0])
            {
                vec[count][1] = max(vec[count][1], v[i][1]);
            }
            else
            {
                count++;
                vec.push_back(v[i]);
            }
        }
        
        return vec;        
    }
};



int main()
{

}