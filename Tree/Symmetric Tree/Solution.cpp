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
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
*/

//Time: O(n)
//Space: O(height of n)
class Solution {
public:
    bool helper(TreeNode * r1, TreeNode * r2)
    {
        if (!r1 && !r2)
            return true;
        else if (!r1 || !r2)
            return false;
        else
            return r1->val == r2->val && helper(r1->left, r2->right) && helper(r1->right, r2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
            
        return helper(root->left, root->right);    
    }
};