class Solution {
    public:
        void traverse(TreeNode* root, vector<int>& res) {
            if (!root) return;
            if (root) {
                traverse(root->left, res);
                res.push_back(root->val);
                traverse(root->right, res);
            }
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            traverse(root, result);
            return result;
        }
};