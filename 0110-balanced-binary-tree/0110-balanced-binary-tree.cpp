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
    int balancedTree(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
            
        }
        
        int left = balancedTree(root->left);
        int right = balancedTree(root->right);
        if(abs(left-right)>1||left==-1||right==-1) return -1;
        return 1 + max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(balancedTree(root)==-1) return false;
        return true;
    }
};