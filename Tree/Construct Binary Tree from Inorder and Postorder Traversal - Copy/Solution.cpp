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
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

class Solution {
public:
    TreeNode* helper(vector<int>& inorder, int start1, int end1, vector<int>& postorder, int start2, int end2) 
    {
        if (start1 > end1)
            return NULL;
        
        if (start1 == end1)
            return new TreeNode(inorder[start1]);
        
        int midIdx1 = find(inorder.begin()+start1, inorder.begin()+end1+1, postorder[end2]) - inorder.begin();
        
        TreeNode * root = new TreeNode(postorder[end2]);
        root->left = helper(inorder, start1, midIdx1-1, postorder, start2, midIdx1-1-start1+start2);
        root->right = helper(inorder, midIdx1+1, end1, postorder, midIdx1-start1+start2, end2-1);
        
        return root;
            
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};