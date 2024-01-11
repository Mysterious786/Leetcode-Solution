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
    int ans = INT_MIN ;
    private:
    void solve(TreeNode* root,int maxi,int mini){
        if(root==NULL){
            ans = max(ans,(maxi-mini));
            return;
        }
        maxi = max(maxi,root->val);
        mini = min(mini,root->val);
        solve(root->left,maxi,mini);
        solve(root->right,maxi,mini);
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return 0;
        solve(root,root->val,root->val);
        return ans;
        
    }
};