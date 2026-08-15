/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void trav(TreeNode* root, int* sum, int low, int high){
        if(root == nullptr) return;

        if(root->val < low) trav(root->right, sum, low, high);
        else if(root->val > high) trav(root->left, sum, low, high);
        else{
            trav(root->left, sum, low, high);
            sum[0] += root->val;
            trav(root->right, sum, low, high);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        trav(root, &sum, low, high);
        return sum;
    }
};
