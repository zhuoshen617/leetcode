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
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/


class Solution {
public:
    TreeNode * clone(TreeNode * root)
    {
        if (!root)
            return NULL;
        
        TreeNode * newRoot = new TreeNode(root->val);
        newRoot->left = clone(root->left);
        newRoot->right = clone(root->right);
        
        return root;  
    }
    vector<TreeNode*> generateTrees(int start, int end) 
    {
        vector<TreeNode*> result;
        if (start > end)
        {
            result.push_back(NULL);
            return result;
        }
        
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode*> l = generateTrees(start, i-1);
            vector<TreeNode*> r = generateTrees(i+1, end);
            
            TreeNode * root = new TreeNode(i);
            for (auto n1 : l)
            {
                for (auto n2 : r)
                {
                    TreeNode * root = new TreeNode(i);
                    root->left = clone(n1);
                    root->right = clone(n2);
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
    vector<TreeNode*> generateTrees(int n) 
    {
        if (n <= 0)
            return vector<TreeNode*>();
        return generateTrees(1, n);
        
    }
};