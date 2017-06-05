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
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValid(TreeNode *root, TreeNode ** prev)
    {
        if (!root)
            return true;
        
        if (!isValid(root->left, prev))
            return false;
        
        if (!(*prev))
            *prev = root; 
        else
        {
            if ((*prev)->val >= root->val)
                return false;
            
            *prev = root;
        }
        
        return isValid(root->right, prev);
            
    }
    bool isValidBST(TreeNode* root) {
        TreeNode * prev = NULL; 
        return isValid(root, &prev);
    }
};