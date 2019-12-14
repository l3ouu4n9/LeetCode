/*

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

E.g.

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.

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
    struct Item {
        int depth;
        TreeNode* n;
    };
    
    int minDepth(TreeNode* root) {
        queue<Item> que;
        
        if(root == NULL) return 0;
        Item qi = {1, root};
        que.push(qi);
        
        while(que.size() > 0){
            qi = que.front();
            que.pop();
            TreeNode* ptr = qi.n;
            int depth = qi.depth;
            
            if(ptr -> left == NULL && ptr -> right == NULL){
                return depth;
            }
            if(ptr -> left != NULL){
                qi.depth = depth + 1;
                qi.n = ptr -> left;
                que.push(qi);
            }
            if(ptr -> right != NULL){
                qi.depth = depth + 1;
                qi.n = ptr -> right;
                que.push(qi);
            }
                
        }
        return 0;
    }
};
