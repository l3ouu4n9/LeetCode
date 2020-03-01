/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:

Input:
    3
   / \
  9  20
    /  \
   15   7

Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

Note:

The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<long> count;
        vector<long> sum;
        vector<double> ret;
        dfs(root, 0, count, sum);
        
        for(int i = 0; i < count.size(); ++i){
            ret.push_back(sum[i] * 1.0 / count[i]);
        }
        
        return ret;
    }
    
    void dfs(TreeNode* root, int level, vector<long>& count, vector<long>& sum){
        if(!root) return;
        
        if(level < count.size()){
            count[level] += 1;
            sum[level] += root -> val;
        } else {
            count.push_back(1);
            sum.push_back(root -> val);
        }
        
        dfs(root -> left, level + 1, count, sum);
        dfs(root -> right, level + 1, count, sum);
        
        return;
    }
};
