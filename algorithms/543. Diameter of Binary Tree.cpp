/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 

          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
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
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        int depth = inOrder(root, max_diameter);
        return max(max_diameter - 1, 0);
    }
    int inOrder(TreeNode* node, int &max_diameter){
        if(node == NULL) return 0;
        int left_depth = inOrder(node -> left, max_diameter);
        int right_depth = inOrder(node -> right, max_diameter);
        
        if(1 + left_depth + right_depth > max_diameter){
            max_diameter = 1 + left_depth + right_depth;
        }
        
        return 1 + max(left_depth, right_depth);
    }
};
