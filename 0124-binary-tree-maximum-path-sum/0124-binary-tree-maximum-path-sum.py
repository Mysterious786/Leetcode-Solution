# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = -1e9
    def maxSum(self, root: Optional[TreeNode]):
        if root == None:
            return 0
        left = max(0,self.maxSum(root.left))
        right = max(0,self.maxSum(root.right))
        self.ans = max(self.ans,root.val + left+right)
        return root.val + max(left,right)
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return self.ans
        self.maxSum(root)
        return self.ans
        