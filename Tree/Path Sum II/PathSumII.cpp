/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

class Solution {
public:
    void helper(TreeNode* root, vector<vector<int>> & result, vector<int> & path, int target, int sum)
    {
        if (!root)
            return;
        
        if (!root->left && !root->right && sum + root->val == target)
        {
            path.push_back(root->val);
            result.push_back(path);
            path.pop_back(); // dont forget to remove this leaf
            return;
        }
        
        path.push_back(root->val);
        helper(root->left, result, path, target, sum+root->val);
        helper(root->right, result, path, target, sum+root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> result;
        vector<int> path;
        helper(root, result, path, sum, 0);
        return result;
        
    }
};