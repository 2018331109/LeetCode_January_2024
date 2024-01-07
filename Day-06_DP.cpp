/*
1235. Maximum Profit in Job Scheduling
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

SUBMISSION IN C++
*/
class Solution
{
public:
    int last(vector<vector<int>>& job, int i)
    {
        int low=0, high=i-1;

        while(low<=high)
        {
            int mid=(high+low)/2;
            if(job[mid][0]<=job[i][1])
            {
                if(job[mid+1][0] <= job[i][1])
                {
                    low=mid+1;
                }
                else
                {
                    return mid;
                }
            }
            else
            {
                high=mid-1;
            }
        }

        return -1;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        int n=startTime.size();

        vector<vector<int>>job(n, vector<int>(3));
        for(int i=0; i<n; i++)
        {
            job[i]= {endTime[i], startTime[i], profit[i]};
        }

        sort(job.begin(), job.end());

        vector<int>dp(n, 0);
        dp[0]=job[0][2];

        for(int i=1; i<n; i++)
        {
            int ex=dp[i-1];
            int in=job[i][2];
            int ind=last(job, i);
            if(ind != -1)
            {
                in+=dp[ind];
            }
            dp[i]=max(in, ex);
        }

        return dp[n-1];

    }
};

