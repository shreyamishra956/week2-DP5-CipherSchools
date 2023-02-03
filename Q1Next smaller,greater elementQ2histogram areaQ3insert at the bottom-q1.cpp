#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {

        int n1 = nums1.size();
        int n2 = nums2.size();
        
        stack<int> st;
        vector<int> temp(n2);
        temp[n2-1] = -1;
        st.push(nums2[n2 - 1]);
            
            
        for(int i = n2-2; i >= 0; i--)
        {
            if((st.size() != 0) && (nums2[i] < st.top()))
            {
                temp[i] = st.top();
                st.push(nums2[i]);
            }
            else
            {
                while((st.size() != 0) && (nums2[i] > st.top()))
                {
                    st.pop();
                }
                if(st.size() == 0)
                {
                    temp[i] = -1;
                    st.push(nums2[i]);
                }
                else
                {
                    temp[i] = st.top();
                    st.push(nums2[i]);
                }
            }
        }
        vector<int> ans;
        
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                if(nums2[j] == nums1[i])
                {
                    ans.push_back(temp[j]);
                }
            }
        }
        return ans;
    }
};


int main()
{

}