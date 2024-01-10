/*
2385. Amount of Time for Binary Tree to Be Infected
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

    The node is currently uninfected.
    The node is adjacent to an infected node.

Return the number of minutes needed for the entire tree to be infected.
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
vector<vector<int>> adj{100005, vector<int>(0)};
int vis[100005];
queue<int>q;
int time=0;
void bfs()
{
    while(!q.empty())
    {
        time++;
        int n=q.size();
        while(n--)
        {
            int now=q.front();
            q.pop();
            for(auto it:adj[now])
            {
                if(!vis[it])
                q.push(it);
                vis[it]=1;
            }
        }
    }
}
void build(TreeNode* root)
{
    if(root==nullptr)
    {
        return;
    }
    if(root->left != nullptr)
    {
        adj[root->left->val].push_back(root->val);
        adj[root->val].push_back(root->left->val);
        build(root->left);
    }
    if(root->right != nullptr)
    {
        adj[root->right->val].push_back(root->val);
        adj[root->val].push_back(root->right->val);
        build(root->right);
    }

}
    int amountOfTime(TreeNode* root, int start) {
        build(root);
        q.push(start);
        vis[start]=1;
        bfs();
        return time-1;
    }
};
