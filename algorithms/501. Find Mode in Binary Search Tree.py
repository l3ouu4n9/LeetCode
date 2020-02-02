"""
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].

Note: If a tree has more than one mode, you can return them in any order.
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def make_counter(self, count, node):
        if node:
            count[node.val] += 1
            self.make_counter(count, node.left)
            self.make_counter(count, node.right)
            
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        count = collections.Counter()
        self.make_counter(count, root)
        if count:
            mx_count = max(count.itervalues())
        l = []
        for i, c in count.items():
            if c == mx_count:
                l.append(i)
        return l
