class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mp;

        q.push({root,{0,0}});

        while(!q.empty()){
            auto front = q.front();
            TreeNode* node = front.first;
            int x = front.second.first;
            int y = front.second.second;
            q.pop();
            mp[x][y].insert(node->val);
            if(node->left!=NULL){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right!=NULL){
                q.push({node->right,{x+1,y+1}});
            }
        }

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