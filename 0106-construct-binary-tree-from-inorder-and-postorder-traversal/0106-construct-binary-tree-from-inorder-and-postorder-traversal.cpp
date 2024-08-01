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
    TreeNode* buildTreeRoot(vector<int>& in, int is, int ie, vector<int>& po, int ps, int pe, map<int,int>& mp) {
        if(ps > pe || is > ie) return NULL;
        
        TreeNode* root = new TreeNode(po[pe]);
        int inRoot = mp[po[pe]];
        int numLeft = inRoot - is;
        
        root->left = buildTreeRoot(in, is, inRoot - 1, po, ps, ps + numLeft - 1, mp);
        root->right = buildTreeRoot(in, inRoot + 1, ie, po, ps + numLeft, pe - 1, mp);
        
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n1 = inorder.size();
        int n2 = postorder.size();
        if(n1 != n2) return NULL;
        
        map<int, int> mp;
        for(int i = 0; i < n1; i++) {
            mp[inorder[i]] = i;
        }
        
        return buildTreeRoot(inorder, 0, n1 - 1, postorder, 0, n2 - 1, mp);
    }
};
