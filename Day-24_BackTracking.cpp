/*
1457. Pseudo-Palindromic Paths in a Binary Tree
Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

SUBMSIION IN C++, IMPLEMENTING BACKTRACKING

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int cnt=0;
    int check(vector<int>& ans)
    {
        int odd=0;
        for(auto it:ans)
        {
            odd+=(it%2);
        }
        return odd<=1;
    }
    void call(TreeNode* node, vector<int>& ans)
    {
        if(node==nullptr)
        {
            return;
        }
        ans[node->val]++;
        if(node->left==nullptr and node->right==nullptr)
        {
            cnt+=check(ans);
        }
        call(node->left, ans);
        call(node->right, ans);
        ans[node->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root)
    {

        //int ans=0;
        vector<int>ans(11, 0);
        call(root, ans);

        return cnt;

    }
};
