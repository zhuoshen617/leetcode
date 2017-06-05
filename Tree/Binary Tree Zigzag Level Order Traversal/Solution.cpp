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
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

class Solution {
public:
    void helper(TreeNode * root, vector<vector<int>> & result, int level)
    {
        if (!root)
            return;
        
        if (level == result.size())
            result.resize(level+1);
        
        result[level].push_back(root->val);
        helper(root->left, result, level+1);
        helper(root->right, result, level+1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        helper(root, result, 0);
        
        for (int i = 0; i < result.size(); i++)
            if (i % 2 == 1)
                reverse(result[i].begin(), result[i].end());
        
        return result;
    }
};