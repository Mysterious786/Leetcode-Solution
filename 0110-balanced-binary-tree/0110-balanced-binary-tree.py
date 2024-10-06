# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = True
    def isB(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        left = self.isB(root.left)
        right = self.isB(root.right)
        if(abs(left-right) > 1):
            self.ans = False
        return 1 + max(left,right)
        
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root == None:
            return True
        val = self.isB(root)
        return self.ans
        