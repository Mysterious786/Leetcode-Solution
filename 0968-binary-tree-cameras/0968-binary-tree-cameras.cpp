class Solution {
    const static int inf = (1<<20);
    map<pair<TreeNode*,pair<bool,bool>>,int> dp;
private:
    int solve(TreeNode* root,int placeCam, int parentCam)
    {
        if(root == NULL)
        {
            if(placeCam) return inf;
            return 0;
        }
        if(root->left == NULL and root->right==NULL)
        {
            if(placeCam)
            {
                return 1;
            }
            else{
                if(parentCam) return 0;
                return inf;
            }
        }
        if(dp.find({root,{placeCam,parentCam}}) != dp.end()) return dp[{root,{placeCam,parentCam}}];
        if(placeCam)
         return dp[{root,{placeCam,parentCam}}] = 1 + min(solve(root->left,0,1),solve(root->left,1,1)) + min(solve(root->right,0,1),solve(root->right,1,1));
        else{
            if(parentCam)
            {
                return dp[{root,{placeCam,parentCam}}] = min(solve(root->left,0,0),solve(root->left,1,0)) + min(solve(root->right,0,0),solve(root->right,1,0));

            }
            else
            {
                int op1 = solve(root->left,1,0) + min(solve(root->right,0,0),solve(root->right,1,0));
                int op2 = solve(root->right,1,0) + min(solve(root->left,0,0),solve(root->left,1,0));
                return dp[{root,{placeCam,parentCam}}] =  min(op1,op2);
            }
        }


    }
public:
    int minCameraCover(TreeNode* root) {
        dp.clear();
        return min(solve(root,0,0),solve(root,1,0));
    }
};