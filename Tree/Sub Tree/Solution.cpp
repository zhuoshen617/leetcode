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
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
*/

/*
[Clarification] Empty target tree is NOT a subtree of any non-empty tree. 
*/

//Time: O(n*m) n: num of node in s, m: num of node in t 
//Space: O(height(s))
class Solution {
public:
    bool isSameTree(TreeNode *s, TreeNode* t)
    {
        if (!s && !t)
            return true;
        else if (!s || !t)
            return false;
        else
            return isSameTree(s->left, t->left) && isSameTree(s->right, t->right) && (s->val == t->val);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if (!s && !t)
            return true;
        else if (!s || !t)
            return false;

        //The idea is, same tree or is SUBTREE of left tree or is SUBTREE of right tree
        return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};