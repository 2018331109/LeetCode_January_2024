/*
2610. Convert an Array Into a 2D Array With Conditions
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

    The 2D array should contain only the elements of the array nums.
    Each row in the 2D array contains distinct integers.
    The number of rows in the 2D array should be minimal.

Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.
SUBMISSION
C++
*/

class Solution
{
public:
 
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
         map<int, int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        vector<vector<int>>ans;
        while(!mp.empty())
        {
            vector<int>tmp;
            for(auto it=mp.begin();it!=mp.end();)
            {
                tmp.push_back(it->first);
                it->second--;
                if(it->second==0)
                {
                    it=mp.erase(it);
                }
                else
                {
                    it++;
                }
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};
