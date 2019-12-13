/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        else{
            if(abs(getHeight(root -> left) - getHeight(root -> right)) > 1){
                return false;
            } else {
                return (isBalanced(root -> left) && isBalanced(root -> right));
            }
        }
    }
    int getHeight(TreeNode* root){
        if(root == NULL) return 0;
        return max(getHeight(root -> left), getHeight(root -> right)) + 1;
    }
};
