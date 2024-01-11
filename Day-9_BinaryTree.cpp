/*
872. Leaf-Similar Trees
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

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
class Solution {
public:
    vector<int>a, b;
    void traverse(TreeNode* root, vector<int>&v)
    {
        if(root == nullptr)
        {
            return;
        }
        if(root->left == nullptr && root->right == nullptr)
        {
            v.push_back(root->val);
            return;
        }
        if(root->left != nullptr)
        {
                traverse(root->left, v);
        }
        if(root->right != nullptr)
        {
            traverse(root->right, v);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        traverse(root1, a);
        traverse(root2, b);
        if(a==b)
        {
            return true;
        }
        return false;
        
    }
};
