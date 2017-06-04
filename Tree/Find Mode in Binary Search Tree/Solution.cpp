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
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
*/

class Solution {
public:
    void helper (TreeNode * root, unordered_map<int, int> & hashmap)
    {
        if (!root)
            return;
        
        hashmap[root->val]++;
        helper(root->left, hashmap);
        helper(root->right, hashmap);
    }
    vector<int> findMode(TreeNode* root) 
    {
        vector<int> result;
        unordered_map<int, int> hashmap;
        helper(root, hashmap);
        
        for (const auto & p : hashmap)
        {
            if (result.empty() || hashmap[result.back()] == p.second)
                ;
            else if (hashmap[result.back()] < p.second)
                result.clear();
            else
                continue;
          
            result.push_back(p.first);
        }
        
        return result;
    }
};