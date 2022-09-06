class Solution {
public:
    TreeNode* recCall(TreeNode* x){
        if(x==NULL) return NULL;                          //return Null for empty subtree
        if(x->left==NULL && x->right==NULL && x->val==0)           //prune the value 0 leaf node
            return NULL;
        if(x->left==NULL && x->right==NULL && x->val==1)           //keep the value 1 leaf node
            return x;
        x->left=recCall(x->left);
        x->right=recCall(x->right);
        if(x->left==NULL && x->right==NULL && x->val==0)   //if a non leaf with value 0 has become leaf, prune it
            return NULL;
        else
            return x;
    }
    TreeNode* pruneTree(TreeNode* root) {
        root=recCall(root);
        return root;
    }
};