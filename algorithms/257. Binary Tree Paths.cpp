/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> v;
        string s;
        if(root != NULL) addPath(root, s, v);
        return v;
    }
    void addPath(TreeNode* root, string s, vector<string> &v){
        if(!s.empty()) s.append("->");
        s.append(to_string(root -> val));
        
        if(root -> left == NULL && root -> right == NULL){
            v.push_back(s);
            return;
        }
        if(root -> left != NULL){
            addPath(root -> left, s, v);
        }
        if(root -> right != NULL){
            addPath(root -> right, s, v);
        }
        return;
    }
};
