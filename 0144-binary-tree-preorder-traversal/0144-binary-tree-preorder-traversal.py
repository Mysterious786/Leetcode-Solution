# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = []
    def pre(self, root: Optional[TreeNode]) -> None:
        if root == None:
            return
        self.ans.append(root.val)
        self.pre(root.left)
        self.pre(root.right)
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.pre(root)
        return self.ans
        