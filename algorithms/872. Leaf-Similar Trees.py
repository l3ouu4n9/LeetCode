"""
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.

      3
    /   \
   5     1
  / \   / \
 6   2 9   8
    / \
   7   4

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Constraints:

Both of the given trees will have between 1 and 200 nodes.
Both of the given trees will have values between 0 and 200
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        leaf1 = []
        leaf2 = []
        self.dfs(root1, leaf1)
        self.dfs(root2, leaf2)
        
        return leaf1 == leaf2
        
        
    def dfs(self, root, leaf):
        if not root:
            return
        
        self.dfs(root.left, leaf)
        self.dfs(root.right, leaf)
        
        if root.left == None and root.right == None:
            leaf.append(root.val)
