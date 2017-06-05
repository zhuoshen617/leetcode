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
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
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
    void helper(TreeNode* root, TreeNode** first, TreeNode** second, TreeNode** prev)
    {
        if (!root)
            return;
        
        helper(root->left, first, second, prev);
     
        if (!(*prev))
            *prev = root;
        else
        {
            if ((*prev)->val > root->val)
            {
                if (!(*first))
                {
                    *first = *prev;
                    *second = root;
                }
                else
                {
                    *second = root;
                }
            }
            
            *prev = root;    
        }
        
        helper(root->right, first, second, prev);
    }

    void recoverTree(TreeNode* root) 
    {
        TreeNode * first = NULL;
        TreeNode * second = NULL;
        TreeNode * prev = NULL;
        helper(root, &first, &second, &prev);
        swap(first->val, second->val);
    }
};
