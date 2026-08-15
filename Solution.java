/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private void trav(TreeNode root, int[] sum, int low, int high){
        if(root == null){
            return;
        }

        if(root.val < low){
            trav(root.right, sum, low, high);
        }
        else if(root.val > high){
            trav(root.left, sum, low, high);
        }
        else{
            trav(root.left, sum, low, high);
            sum[0] += root.val;
            trav(root.right, sum, low, high);
        }
    }

    public int rangeSumBST(TreeNode root, int low, int high) {
        int[] sum = {0};
        trav(root, sum, low, high);
        return sum[0];
    }
}
