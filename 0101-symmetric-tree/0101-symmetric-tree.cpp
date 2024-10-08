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
    private:
    bool sym(TreeNode* p,TreeNode* q)
    {
        if(p==NULL and q==NULL) return true;
        if(p==NULL or q==NULL) return false;
        if(p->val!=q->val) return false;
        return sym(p->left,q->right) and sym(p->right,q->left);
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || root->left==NULL and root->right==NULL) return root;
        return sym(root->left,root->right);
    }
};