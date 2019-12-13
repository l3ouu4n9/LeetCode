/*

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> node_que;
        TreeNode* ptr;
        
        node_que.push(root);
        
        while(true){
            vector<int> tmp;
            queue<TreeNode*> tmp_que;
            while(node_que.size() > 0){
                ptr = node_que.front();
                node_que.pop();
                if(ptr != NULL){
                    tmp.push_back(ptr -> val);
                    if(ptr -> left != NULL) tmp_que.push(ptr -> left);
                    if(ptr -> right != NULL) tmp_que.push(ptr -> right);
                }
            }
            if(tmp.size() > 0){
                ans.push_back(tmp);
                node_que = tmp_que;
            }
            else break;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
};
