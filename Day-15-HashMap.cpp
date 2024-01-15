/*
2225. Find Players With Zero or One Losses
You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

    answer[0] is a list of all players that have not lost any matches.
    answer[1] is a list of all players that have lost exactly one match.

The values in the two lists should be returned in increasing order.

Note:

    You should only consider the players that have played at least one match.
    The testcases will be generated such that no two matches will have the same outcome.

SUBMISSION IN C++
*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int player[100005]={}, loss[100005]={};
        for(auto it:matches)
        {
            player[it[0]]=1, player[it[1]]=1;
            loss[it[1]]++;
        }
        vector<vector<int>>ans(2, vector<int>());
        for(int i=1;i<100005;i++)
        {
            if(!player[i])
            {
                continue;
            }
            if(loss[i]==0)
            {
                ans[0].push_back(i);
            }
            if(loss[i]==1)
            {
                ans[1].push_back(i);
            }
        }

        return ans;
        
    }
};
