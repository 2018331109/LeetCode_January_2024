/*
739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

SUBMISSION IN C++
*/
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& v)
    {
        
        stack<pair<int, int>>st;
        int n=v.size();
        vector<int>ans(n, 0);
        st.push({v[n-1], 0});
        ans[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            int cnt=1;
            int removal=0;
            while(st.size()>0 and st.top().first<=v[i])
            {
                //removal++;
                cnt+=st.top().second;
                st.pop();
            }
            if(st.size()==0)
            {
                ans[i]=0;
                st.push({v[i], 0});
            }
            else
            {
                ans[i]=cnt;
                st.push({v[i], ans[i]});
            }
        }
        
        return ans;

    }
};
