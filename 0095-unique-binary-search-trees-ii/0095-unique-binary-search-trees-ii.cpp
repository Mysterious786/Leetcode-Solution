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
    vector<TreeNode*> f(int start,int end){
        vector<TreeNode*> ans;
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> lefty = f(start,i-1);
            vector<TreeNode*> righty = f(i+1,end);
            for(auto a : lefty){
                for(auto b : righty ){
                    TreeNode* newNode = new TreeNode(i);
                    newNode->left = a;
                    newNode->right = b;
                    ans.push_back(newNode);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        
        return f(1,n);
        
    }
};