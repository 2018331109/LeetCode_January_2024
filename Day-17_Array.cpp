/*
1207. Unique Number of Occurrences
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

SUBMISSION IN C++
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        int cnt=1;
        sort(arr.begin(), arr.end());
        vector<int>v;
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1])
            {
                cnt++;
            }
            else
            {
                v.push_back(cnt);
                cnt=1;
            }
        }
        v.push_back(cnt);
        sort(v.begin(), v.end());
        n=v.size();
        for(int i=1;i<n;i++)
        {
            if(v[i]==v[i-1])
            {
                return false;
            }
        }
        return true;
    }
};
