/*
1074. Number of Submatrices That Sum to Target

Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

SUBMISSION IN C++
*/

class Solution
{
public:

    int call(vector<int>&nums, int k)
    {
        map<int, int>mp;
        mp[0]=1;
        int total=0;
        int cnt=0;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            total+=nums[i];
            int rm=total-k;
            cnt+=mp[rm];
            mp[total]+=1;
        }
        
        return cnt;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        int ans=0;
        int n=matrix.size(), m=matrix[0].size();
        for(int i=0; i<n; i++)
        {
            vector<int>v(m, 0);
            for(int j=i; j<n; j++)
            {
                for(int k=0; k<m; k++)
                {
                    v[k]+=matrix[j][k];
                }
                ans+=call(v, target);
            }
        }
        
        return ans;
    }
};

