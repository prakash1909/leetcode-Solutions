class Solution {
public:
    int f(TreeNode *root,int mx){
        if(!root) return 0;
        return (root->val>=mx?1:0)+f(root->left,max(mx,root->val))+f(root->right,max(mx,root->val));
    }
    int goodNodes(TreeNode* root) {
        return f(root,-1e9);
    }
};