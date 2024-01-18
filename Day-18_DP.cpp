/*
70. Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

SUBMISSION IN C++
*/

class Solution {
public:
    int climbStairs(int n) {
        int a=1, b=1;
        for(int i=2;i<=n;i++)
        {
            int temp=b;
            b=a+b;
            a=temp;
        }
        return b;
        
    }
};
