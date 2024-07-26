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
    bool sym(TreeNode* r1,TreeNode* r2){
        if(r1==NULL and r2==NULL) return true;
        if(r1==NULL) return false;
        if(r2==NULL) return false;
        if(r1->val!=r2->val) return false;
        
        return (sym(r1->left,r2->right) and sym(r1->right,r2->left)) ;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL || (root->left==NULL and root->right==NULL)) return true;
        
        return sym(root->left,root->right);
        
    }
};