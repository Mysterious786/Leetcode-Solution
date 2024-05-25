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
    vector<TreeNode*> find(int start,int end){
        vector<TreeNode*> ans;
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }
            for(int i=start;i<=end;i++){
                vector<TreeNode*> lefty = find(start,i-1);
                vector<TreeNode*> righty = find(i+1,end);
                for(int j=0;j<lefty.size();j++){
                    for(int k=0;k<righty.size();k++){
                        TreeNode* newNode = new TreeNode(i);
                        newNode->left = lefty[j];
                        newNode->right = righty[k];
                        ans.push_back(newNode);
                    }
                }
            }
            
        
        return ans;
        
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return find(1,n);
        
    }
};