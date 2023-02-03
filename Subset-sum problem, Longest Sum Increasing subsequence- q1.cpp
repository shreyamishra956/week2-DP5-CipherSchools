#include<bits/stdc++.h>
using namespace std;


bool find(vector<int>nums,int n,int sum,vector<vector<int>>&dp)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0 && j==0)
                dp[i][j]=1;
            else if(j==0)
                dp[i][j]=1;
            else if(i==0)
                dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(nums[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else if(nums[i-1]<=j)
            dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
        }
    }
   return dp[n][sum];
}
bool canPartition(vector<int>& nums) 
{
    int sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
    }
    bool ans;
    if(sum%2!=0)
        return false;
    else
    {
        int t=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
        ans=find(nums,n,t,dp);
    }   
    return ans;
}


int main()
{
    
}