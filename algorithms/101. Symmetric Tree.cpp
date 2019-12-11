/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    bool isMirror(TreeNode* n1, TreeNode* n2){
        if(n1 == NULL && n2 == NULL) return true;
        else if(n1 == NULL || n2 == NULL) return false;
        else{
            return (n1 -> val == n2 -> val) &&\
                (isMirror(n1 -> left, n2 -> right)) &&\
                (isMirror(n1 -> right, n2 -> left));
        }
    }
};
