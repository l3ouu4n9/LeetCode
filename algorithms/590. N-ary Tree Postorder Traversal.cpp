/*
Given an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Example 1:

     1
   / | \
  3  2  4
 / \
5   6

Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ret;
        traversal(root, ret);
        return ret;
    }
    void traversal(Node* root, vector<int>& ret){
        if(!root) return;
        for(int i = 0; i < root -> children.size(); ++i){
            traversal(root -> children[i], ret);
        }
        ret.push_back(root -> val);
    }
};
