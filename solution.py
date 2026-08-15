# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def trav(self, root, s, low, high):
        if not root: 
            return

        if root.val < low:
            self.trav(root.right, s, low, high)
        elif root.val > high:
            self.trav(root.left, s, low, high)
        else:
            self.trav(root.left, s, low, high)
            s[0] += root.val
            self.trav(root.right, s, low, high)
        
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        s = [0]
        self.trav(root, s, low, high)
        return s[0]
