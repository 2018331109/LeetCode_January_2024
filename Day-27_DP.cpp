/*
629. K Inverse Pairs Array
For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.

SUBMISSION IN C++
*/

class Solution
{
public:

    const int mod=1e9+7;
    //int dp[1001][1001] = {1};
    int kInversePairs(int n, int k)
    {
        int dp[1001][1001] = {1};
        //memset(dp, 1, sizeof(dp));
        //vector<vector<int>>dp(1003, vector<int>(1003, 1));
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<k;j++)
//            {
//                cout<<dp[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        //int dp[1001][1001] = { 1 };
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=k; j++)
            {
                for(int it=0; it<=min(j, i-1); it++)
                {
                    dp[i][j]+=(dp[i-1][j-it])%mod;
                    dp[i][j]%=mod;
                }
            }
        }
        return dp[n][k];
    }
};

