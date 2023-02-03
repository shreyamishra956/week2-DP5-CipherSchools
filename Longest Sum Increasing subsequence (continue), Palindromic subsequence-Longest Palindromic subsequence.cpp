#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j]=1+f(s,t,i-1,j-1,dp);
        return dp[i][j]=max(f(s,t,i-1,j,dp),f(s,t,i,j-1,dp));
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end()); 
        int n=s.size()-1;
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return f(s,t,n,n,dp);
    }
};

int main()
{
    
}