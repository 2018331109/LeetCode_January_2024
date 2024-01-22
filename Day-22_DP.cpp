/*
645. Set Mismatch
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

SUBMISSION IN C++
*/

// in place efficient
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int d=0;
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])-1]<0)
            {
                d=abs(nums[i]);
            }
            else
            {
                nums[abs(nums[i])-1]*=-1;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                return {d, i+1};
            }
        }

        //return ans;
        return {0, 0};
        
    }
};

// extra space

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1, 0);
        for(auto it:nums)
        {
            dp[it]+=1;

        }
        vector<int>ans(2);
        for(int i=1;i<=n;i++)
        {
            if(dp[i]==2)
            {
                ans[0]=i;
            }
            if(dp[i]==0)
            {
                ans[1]=i;
            }
        }

        return ans;
        
    }
};
