/*

1026. Maximum Difference Between Node and Ancestor
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.
SUBMISSION IN C++
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
    int mn, mx;
    int ans;
    void traverse(TreeNode* root, int mx, int mn)
    {
         if(root==nullptr)
         {
             ans=max(ans, mx-mn);
             return;
         }
         mx=max(mx, root->val);
         mn=min(mn, root->val);
         traverse(root->left, mx, mn);
         traverse(root->right, mx, mn);
    }
    int maxAncestorDiff(TreeNode* root)
    {
        mn=100005;
        mx=0;
        traverse(root, mx, mn);
        return ans;

    }
};
