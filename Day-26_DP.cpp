/*
576. Out of Boundary Paths

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

SUBMISSION IN C++ USING DYNAMIC PROGRAMMING

*/

class Solution {
public:
    const int mod=1e9+7;
    int dp[55][55][55];
    int call(int r, int c, int x, int y, int rm)
    {
        if(x<0 || y<0 || x>=r || y>=c)
        {
            return 1;
        }
        
        if(rm==0)
        {
            return 0;
        }

        if(dp[x][y][rm] != -1)
        {
            return dp[x][y][rm];
        }
        
        long long res=0;
        res+=call(r, c, x-1, y, rm-1)%mod;
        res+=call(r, c, x+1, y, rm-1)%mod;
        res+=call(r, c, x, y+1, rm-1)%mod;
        res+=call(r, c, x, y-1, rm-1)%mod;

        return dp[x][y][rm]=(int)(res%mod);
    }
    int findPaths(int m, int n, int k, int x, int y) {
        memset(dp, -1, sizeof(dp));

        int ans=call(m, n, x, y, k);
        return ans%mod;
        
    }
};
