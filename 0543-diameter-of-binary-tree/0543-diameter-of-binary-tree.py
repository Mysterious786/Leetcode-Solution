# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = 0  # Class attribute to store the maximum diameter

    def final(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        # Recursively calculate the height of left and right subtrees
        left = self.final(root.left)
        right = self.final(root.right)

        # Update the maximum diameter
        self.ans = max(self.ans, left + right)

        # Return the height of the current subtree
        return 1 + max(left, right)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.final(root)
        return self.ans  # Return the maximum diameter
