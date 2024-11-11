
class Solution {
   int dia(TreeNode* root, int& ans)
    {
        if(root==NULL) return 0;

        int left = dia(root->left,ans);
        int right = dia(root->right,ans);
        ans = max(ans,left+right);
        return 1 + max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int hei = dia(root,ans);
        return ans;
    }
};