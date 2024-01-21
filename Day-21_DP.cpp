/*
198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

*/

// SUBMISSION WITH MEMOIZATION DP

class Solution {
public:
    int n, ans;
     

    int call(vector<int>& nums, int it, vector<int>& memo)
    {
        if(it>=n)
        {
            return 0;
        }
        if(memo[it]!=-1)
        {
            return memo[it];
        }
        
        return memo[it]=max(nums[it]+call(nums, it+2, memo), call(nums, it+1, memo));
    }
    int rob(vector<int>& nums) {
        
        n=nums.size();
        vector<int>memo(n+1, -1);
        ans=call(nums, 0, memo);
        return ans;
    }
    
};

//SUBMISSION WITH LINEAR DP
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1, 0);
        dp[1]=nums[0];
        for(int i=2;i<=n;i++)
        {
            dp[i]=max(dp[i-1], dp[i-2]+nums[i-1]);
        }

        cout<<dp[n]<<endl;

        return dp[n];
    }
};
