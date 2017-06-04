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
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].
*/

class Solution {
public:
    void helper(TreeNode* root, vector<int> & result)
    {
        if (!root)
            return;
        
        helper(root->left, result);
        result.push_back(root->val);
        helper(root->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        helper(root, result);
        return result;
    }
};