/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2


Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
    int max_length = 0;
    int longestUnivaluePath(TreeNode* root) {
        DFS(root);
        return max_length;
    }
    int DFS(TreeNode* root){
        if(!root) return 0;
        int left = DFS(root -> left);
        int right = DFS(root -> right);
        
        int left_arrow = 0;
        int right_arrow = 0;
        if(root -> left && root -> left -> val == root -> val) left_arrow = left + 1;
        if(root -> right && root -> right -> val == root -> val) right_arrow = right + 1;
        
        max_length = max(max_length, left_arrow + right_arrow);
        return max(left_arrow, right_arrow);
    }
};
