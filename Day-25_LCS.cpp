/*
1143. Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.

SUBMISSION IN C++
*/
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n=text1.size(), m=text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
                }
            }
        }

        cout<<dp[n][m];
        return dp[n][m];
    }
};

