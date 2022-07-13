class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> v;
        if(root == NULL) {
            return res;
        }
        queue <TreeNode *> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        while(!pendingNodes.empty()) {
            TreeNode* front = pendingNodes.front();
            pendingNodes.pop();
            if(front == NULL) {
                res.push_back(v);
                v.clear();
                if(pendingNodes.size() > 0) {
                    pendingNodes.push(NULL);
                }
            }
            else {
                v.push_back(front -> val);
                if(front -> left) {
                    pendingNodes.push(front -> left);
                }
                if(front -> right) {
                    pendingNodes.push(front -> right);
                }
            }
        }
        return res;
    }
};