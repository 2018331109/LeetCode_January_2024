/*
446. Arithmetic Slices II - Subsequence
Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

    For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
    For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.

A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

    For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].

The test cases are generated so that the answer fits in 32-bit integer.

SUBMISSION IN C++
*/
#define ll long long
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n=nums.size();
        int ans=0;
        vector<map<ll, int>>dp(n);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                ll dif=(ll)nums[i]-(ll)nums[j];
                
                if(dif<=INT_MIN || dif>=INT_MAX)
                {
                    continue;
                }
                int cnt=0;
                if(dp[j].find(dif) != dp[j].end())
                {
                    cnt=dp[j][dif];
                }
                ans+=cnt;
                dp[i][dif]+=cnt+1;
            }
        }
        
        return ans;

    }
};

