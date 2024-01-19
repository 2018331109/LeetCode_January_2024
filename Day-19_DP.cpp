/*
931. Minimum Falling Path Sum
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

SUBMISSION IN C++
*/

class Solution
{
public:
    int n;
    int call(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp)
    {
        if(j>=0 && j<=n-1 && i==n-1)
        {
            return matrix[i][j];
        }
        if(i>=n || j>=n || j<0)
        {
            return INT_MAX;
        }

        if(dp[i][j] != INT_MAX)
        {
            return dp[i][j];
        }

        return dp[i][j]=matrix[i][j]+min(call(matrix, i+1, j, dp), min(call(matrix, i+1, j-1, dp), call(matrix, i+1, j+1, dp)));

    }
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        n=matrix.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, INT_MAX));
        int ans=INT_MAX;

        for(int i=0; i<n; i++)
        {
            ans=min(ans, call(matrix, 0, i, dp));
        }

        return ans;
    }
};

