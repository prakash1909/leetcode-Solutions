class Solution {
public:
    vector<TreeNode *> list;
    void f_search(TreeNode * cur) {
        if(cur == nullptr) return;
        list.push_back(cur);
        f_search(cur -> left);
        f_search(cur -> right);
    }
    void flatten(TreeNode* root) {                
        f_search(root);
        for (int i=1; i<list.size(); ++i) {
            list[i-1]->left = nullptr;
            list[i-1]->right = list[i];
        }
    }
};