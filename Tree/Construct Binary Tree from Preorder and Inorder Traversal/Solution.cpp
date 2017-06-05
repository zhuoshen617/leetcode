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
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

class Solution {
public:
    TreeNode* helper(vector<int>& preorder, int start1, int end1, vector<int>& inorder, int start2, int end2) 
    {
        if (start1 > end1)
            return NULL;
        
        if (start1 == end1)
            return new TreeNode(preorder[start1]);
        
        int midIdx2 = find(inorder.begin()+start2, inorder.begin()+end2+1, preorder[start1]) - inorder.begin();
        TreeNode * root = new TreeNode(preorder[start1]);
        root->left = helper(preorder, start1+1, midIdx2-start2+start1, inorder, start2, midIdx2-1);
        root->right = helper(preorder, midIdx2-start2+start1+1, end1, inorder, midIdx2+1, end2);
        
        return root;
            
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};