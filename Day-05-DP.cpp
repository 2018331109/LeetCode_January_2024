/*
300. Longest Increasing Subsequence
Given an integer array nums, return the length of the longest strictly increasing
subsequence
.

SUBMISSION IN C++
*/
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>dp;

        for(int i=0; i<n; i++)
        {
            int ind=lower_bound(dp.begin(), dp.end(), nums[i])-dp.begin();
            if(ind == dp.size())
            {
                dp.push_back(nums[i]);
            }
            else
            {
                dp[ind]=nums[i];
            }
        }

        return dp.size();

    }
};

