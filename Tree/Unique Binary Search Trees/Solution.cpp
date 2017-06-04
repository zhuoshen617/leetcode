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
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    unordered_map<int, int> hashmap;
    int numTrees(int n) 
    {   
        if (n == 0)
            return 1;
        
        if (hashmap.count(n))
            return hashmap[n];
            
        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            int l = numTrees(i-1);
            int r = numTrees(n-i);
            
            result += l*r;
        }
        
        hashmap[n] = result;
        return hashmap[n];
    }
};