/*
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:

Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
 

Example 2:

Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
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
    int findSecondMinimumValue(TreeNode* root) {
        return SearchInTree(root, -1);
    }
    
    int SearchInTree(TreeNode* root, int min_val){
        if(!root || root -> left == NULL) return min_val;

        if(root -> left -> val > root -> right -> val){
            if(min_val != -1){
                if(root -> left -> val > min_val) return SearchInTree(root -> right, min_val);
            } return SearchInTree(root -> right, root -> left -> val);
        } else if(root -> left -> val < root -> right -> val){
            if(min_val != -1){
                if(root -> right -> val > min_val) return SearchInTree(root -> left, min_val);
            } return SearchInTree(root -> left, root -> right -> val);
        } 
        return min(SearchInTree(root -> left, min_val), SearchInTree(root -> right, min_val));
    }
};
