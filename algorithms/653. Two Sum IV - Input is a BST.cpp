/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
 

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
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
    bool findTarget(TreeNode* root, int k) {
        return BST(root, root, k);
    }
    
    bool BST(TreeNode* node, TreeNode* root, int k){
        if(!node) return false;
        
        int target = k - node -> val;
        
        TreeNode* ptr = root;
        
        // Search from root
        while(ptr){
            if(ptr -> val > target) ptr = ptr -> left;
            else if(ptr -> val < target) ptr = ptr -> right;
            else {
                if(ptr == node) break;
                else return true;
            }
        }
        
        return BST(node -> left, root, k) || BST(node -> right, root, k);
    }
};
