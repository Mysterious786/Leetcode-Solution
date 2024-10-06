# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lca(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode'):
        if root == None or root == p or root == q:
            return root
        left = self.lca(root.left,p,q)
        right = self.lca(root.right,p,q)
        if left == None:
            return right
        if right == None:
            return left
        return root
        
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return self.lca(root,p,q)