/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        
        int num = 0;
        if(root -> left != NULL){
            if(root -> left -> left == NULL && root -> left -> right == NULL) num += root -> left -> val;
            else num += sumOfLeftLeaves(root -> left);
        }
        num += sumOfLeftLeaves(root -> right);
        return num;
    }
};
