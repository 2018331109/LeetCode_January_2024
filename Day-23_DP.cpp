/*
1239. Maximum Length of a Concatenated String with Unique Characters

You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

SUBMISSION IN C++, DYNAMIC PROGRAMMING IMPLEMENTATION
*/

class Solution
{
public:
    
    unordered_map<string, int>memo;
    
    bool duplicate(string a, string b)
    {
        unordered_map<char, int>mp;
        for(auto it:a)
        {
            mp[it]++;
            if(mp[it]>1)
            {
                return true;
            }
        }
        for(auto it:b)
        {
            mp[it]++;
            if(mp[it]>1)
            {
                return true;
            }
        }
        
        return false;
    }
    
    int call(vector<string>& arr, string temp, int i, int n)
    {
        if(i>=n)
        {
            return temp.length();
        }
        if(memo[temp])
        {
            return memo[temp];
        }
        int include=0, exclude=0;
        if(duplicate(temp, arr[i]))
        {
            exclude=call(arr, temp, i+1, n);
        }
        else
        {
            exclude=call(arr, temp, i+1, n);
            include=call(arr, temp+arr[i], i+1, n);
        }
        
        return memo[temp] = max(include, exclude);
    }
    
    int maxLength(vector<string>& arr)
    {
        int n=arr.size();
        string temp="";
        
        int ans=call(arr, temp, 0, n);
        
        return ans;

    }
};

