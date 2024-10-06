# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = True
    def isSame(self, p: Optional[TreeNode], q: Optional[TreeNode]):
        if p==None and q==None:
            return True
        
        if p==None or q == None:
            return False
        if p.val != q.val:
            return False
        
        left_check = self.isSame(p.left,q.left)
        right_check = self.isSame(p.right,q.right)
        return left_check & right_check
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        return self.isSame(p,q)
        
        