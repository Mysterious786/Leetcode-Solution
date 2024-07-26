class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // things needed
        //1. queue (treeNode,<x,y>)
        queue<pair<TreeNode*,pair<int,int>>> q;
        // map neede to map things vertical
        map<int,map<int,multiset<int>>> mp;

        // suppose I need to move left and currently on (x,y) that means ===> (x+1,y-1);
        // For right (x,y) ===> (x+1,y+1);

        // lets push root , root on the origin (0,0)

        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;
            mp[x][y].insert(node->val);
            if(node->left!=NULL){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right!=NULL){
                q.push({node->right,{x+1,y+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto it : mp){
            vector<int> v;
            for(auto i : it.second){
                v.insert(v.end(),i.second.begin(),i.second.end());

            }
            ans.push_back(v);
        }
        return ans;


        
    }
};