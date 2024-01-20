/*
907. Sum of Subarray Minimums
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

SUBMISSION IN C++
*/

class Solution
{
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>a(n), b(n);
        stack<pair<int, int>>left, right;
        for(int i=0; i<n; i++)
        {
            int cnt=1;
            while(!left.empty() && left.top().first>arr[i])
            {
                cnt+=left.top().second;
                left.pop();
            }
            left.push({arr[i], cnt});
            a[i]=cnt;
        }

        for(int i=n-1; i>=0; i--)
        {
            int cnt=1;
            while(!right.empty() && right.top().first>=arr[i])
            {
                cnt+=right.top().second;
                right.pop();
            }
            right.push({arr[i], cnt});
            b[i]=cnt;
        }

        int ans=0;
        for(int i=0; i<n; i++)
        {
            long long ab=(a[i]*b[i])%mod;
            ans+=(long long)(ab*arr[i])%mod;
            ans%=mod;
        }

        return ans;

    }
};

