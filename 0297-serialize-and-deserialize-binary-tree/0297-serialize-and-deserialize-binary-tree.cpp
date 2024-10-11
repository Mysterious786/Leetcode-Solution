/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    // Preorder traversal to serialize the tree
    void preOrder(TreeNode* root, vector<string>& data) {
        if (root == nullptr) {
            data.push_back("#");
            return;
        }
        data.push_back(to_string(root->val));
        preOrder(root->left, data);
        preOrder(root->right, data);
    }

    // Split the serialized string by comma
    vector<string> split(const string& data) {
        vector<string> result;
        string value = "";
        for (char ch : data) {
            if (ch == ',') {
                result.push_back(value);
                value = "";
            } else {
                value += ch;
            }
        }
        // Push the last segment
        if (!value.empty()) {
            result.push_back(value);
        }
        return result;
    }

    // Rebuild the tree using pre-order traversal
    TreeNode* solve(vector<string>& nums, int& i) {
        if (nums[i] == "#") {
            i++;
            return nullptr;
        }
        // Convert string to integer correctly
        int val = stoi(nums[i]);
        TreeNode* node = new TreeNode(val);
        i++;
        node->left = solve(nums, i);
        node->right = solve(nums, i);
        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";  // Handle empty tree

        vector<string> ses;
        preOrder(root, ses);
        string serialized = "";
        for (const string& str : ses) {
            serialized += str + ",";
        }
        serialized.pop_back();  // Remove the last comma
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#") return nullptr;  // Handle empty tree

        vector<string> des = split(data);
        int index = 0;
        return solve(des, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
