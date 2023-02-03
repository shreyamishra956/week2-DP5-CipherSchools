#include<bits/stdc++.h>
using namespace std;

#define POSSIBLE_MOVES 4
int xMoves[] = {1, -1, 0, 0};
int yMoves[] = {0, 0, 1, -1};

int longestIncreasingPathLength(const vector<vector<int>> &mat, vector<vector<bool>> &visited, vector<vector<int>> &dp
                                int x, int y, const int &row, const int &col, int &maxResult)
{
    if(dp[x][y] > 0)
    {
        return dp[x][y];
    }

    visited[x][y] = true;
    int currMoves = 1;
    for(int i = 0; i < POSSIBLE_MOVES; i++)
    {
        int nextX = x + xMoves[i];
        int nextY = y + yMoves[i];
        if(isSafe(mat, visited, dp, nextX, nextY, row, col) && mat[x][y] < mat[nextX][nextY])
        {
            currMoves = max(currMoves, longestIncreasingPathLength(mat, visited, dp, nextX, nextY, row, col, currMoves));
        }
    }

    dp[x][y] = currMoves;
    maxResult = max(maxResult, currMoves);
    visited[x][y] = false;
    return dp[x][y];
}



int longestIncreasingPathLength(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();

    vector<vector<bool>> visited(row, vector<bool> (col, false));
    vector<vector<int>> dp(row, vector<int>(col, 0));

    int maxcount = 1;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(dp[i][j] == 0)
            {
                dp[i][j] = longestIncreasingPathLength(mat, visited, dp, 0, row, col, maxcount);
            }
        }
    }
    return maxcount;
}


int main()
{

}