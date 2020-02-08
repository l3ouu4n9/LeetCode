/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
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
    TreeNode* prev = NULL;
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        calc_diff(root, ans);
        return ans;
    }
    void calc_diff(TreeNode* curr, int &ans){
        if(curr == NULL) return;
        calc_diff(curr -> left, ans);
        
        if(prev != NULL){
            int diff = abs(prev -> val - curr -> val);
            if(ans > diff) ans = diff;
        }
        prev = curr;
        calc_diff(curr -> right, ans);
    }
    
};
