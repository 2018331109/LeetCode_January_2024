/*
2870. Minimum Number of Operations to Make Array Empty
You are given a 0-indexed array nums consisting of positive integers.

There are two types of operations that you can apply on the array any number of times:

    Choose two elements with equal values and delete them from the array.
    Choose three elements with equal values and delete them from the array.

Return the minimum number of operations required to make the array empty, or -1 if it is not possible.

SUBMISSION: C++
*/
class Solution
{
public:
    int minOperations(vector<int>& nums)
    {
        int n=nums.size();
        map<int, int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        int ans=0;
        for(auto it:mp)
        {
            if(it.second==1)
            {
                return -1;
            }
            if(it.second%3==2)
            {
                ans+=(it.second/3)+1;
            }
            else if(it.second%3==0)
            {
                ans+=it.second/3;
            }
            else
            {
                ans+=(it.second-4)/3+2;
            }
        }
        
        return ans;

    }
};

