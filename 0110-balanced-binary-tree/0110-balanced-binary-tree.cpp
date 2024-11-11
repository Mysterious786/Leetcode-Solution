class Solution {
private:
    int check(TreeNode* root)
    {
        if(root == NULL) return 0 ;

        int left = check(root->left);
        int right = check(root->right);
        if(left == -1 || right == -1||abs(left-right)>1) return -1;
        return 1 + max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        int heigthCheck = check(root);
        return heigthCheck!=-1;
    }
};