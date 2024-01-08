/*
938. Range Sum of BST
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

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
    int ans=0;
    int traverse(TreeNode* root, int l, int r)
    {
        if(root)
        {
            traverse(root->left, l, r);
            if(root->val>=l && root->val<=r)
            {
                ans+=root->val;
                //cout<<ans<<endl;
            }
            traverse(root->right, l, r);
        }
        cout<<ans<<endl;
        return ans;
    }
    int rangeSumBST(TreeNode* root, int l, int r)
    {
        if(!root)
        {
            return 0;
        }
        return traverse(root, l, r);

    }
};

