class Solution {
public:
    vector<int> start, end, depth;
    
    // Helper function to count nodes in the tree
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    // Depth calculation function
    void depthy(TreeNode* root, int deep) {
        if (!root) return;
        depth[start[root->val]] = deep;
        if (root->left) depthy(root->left, deep + 1);
        if (root->right) depthy(root->right, deep + 1);
    }
    
    // Euler Tour function to set start and end indices
    void EulerTour(TreeNode* root, int& ind) {
        start[root->val] = ind;
        depth[ind] = depth[start[root->val]]; // Set the depth here for the node
        if (root->left) {
            ind++;
            EulerTour(root->left, ind);
        }
        if (root->right) {
            ind++;
            EulerTour(root->right, ind);
        }
        end[root->val] = ind;
    }
    
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n = countNodes(root);
        int ind = 1;
        
        start.assign(n + 1, 0);
        end.assign(n + 1, 0);
        depth.assign(n + 1, 0);
        
        // Perform Euler tour to initialize start, end, and depth
        EulerTour(root, ind);
        
        // Calculate depths correctly after Euler tour
        depthy(root, 0);
        
        // Initialize prefix and suffix maximum depth arrays
        vector<int> prefMax(n + 2, 0), suffMax(n + 2, 0);
        
        for (int i = 1; i <= n; i++) prefMax[i] = max(depth[i], prefMax[i - 1]);
        for (int i = n; i >= 1; i--) suffMax[i] = max(depth[i], suffMax[i + 1]);
        
        // Process queries to get results
        vector<int> res;
        for (auto q : queries) {
            int l = start[q], r = end[q];
            res.push_back(max(prefMax[l - 1], suffMax[r + 1]));
        }
        
        start.clear(), end.clear(), depth.clear();
        return res;
    }
};
