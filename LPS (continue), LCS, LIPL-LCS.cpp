#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) 
{
    vector<vector<int>> t(text1.length() + 1, vector<int> (text2.length() + 1, 0));
    
    
    for(int i = 1; i <= text1.length(); i++)
    {
        for(int j = 1; j <= text2.length(); j++)
        {
            if(text1[i - 1] == text2[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    
    return t[text1.length()][text2.length()];
}

int main()
{

}