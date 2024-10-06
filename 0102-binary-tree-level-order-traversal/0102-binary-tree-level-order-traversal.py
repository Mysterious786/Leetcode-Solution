# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def __init__(self):
        self.ans = []
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root == None:
            return self.ans
        q = deque([root])
        
        while len(q) > 0:
            size = len(q)
            v= []
            for i in range(0,size):
                ele = q.popleft()
                v.append(ele.val)
                if ele.left != None:
                    q.append(ele.left)
                if ele.right != None:
                    q.append(ele.right)
            self.ans.append(v)
        return self.ans
                
        
        
        
        