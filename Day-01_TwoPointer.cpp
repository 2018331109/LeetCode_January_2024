/*
455. Assign Cookies
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

SOLUTION
C++
*/
class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int n=g.size(), m=s.size();
        int l=0, r=0;
        sort(g.begin(), g.end()), sort(s.begin(), s.end());
        
        while(l<n && r<m)
        {
            if(g[l]<=s[r])
            {
                l++, r++;
            }
            else
            {
                r++;
            }
        }
        
        return min(l, r);
    }
};

