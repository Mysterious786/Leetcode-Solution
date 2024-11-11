
class Solution {
private:
    int path(TreeNode* root, int& ans)
    {
        if(root==NULL) return 0;
        int left = max(0,path(root->left,ans));
        int right = max(0,path(root->right,ans));
        ans = max(ans,left+right+root->val);
        return root->val + max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int check = path(root,ans);
        return ans;
    }
};