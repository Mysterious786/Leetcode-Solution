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
    void f(TreeNode* root,vector<int>& v){
        if(root==NULL) return;
        if(root->left==NULL && root->right ==NULL){
            v.push_back(root->val);
            return;
            
        }
        f(root->left,v);
        f(root->right,v);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        f(root1,tree1);
        f(root2,tree2);
       return tree1 == tree2;
        
    }
};