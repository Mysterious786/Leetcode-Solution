# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = 0
    def dia(self, root: Optional[TreeNode]):
        if root == None:
            return 0
        left = self.dia(root.left)
        right = self.dia(root.right)
        self.ans = max(self.ans, left+right)
        return 1 + max(left,right)
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.dia(root)
        return self.ans
        