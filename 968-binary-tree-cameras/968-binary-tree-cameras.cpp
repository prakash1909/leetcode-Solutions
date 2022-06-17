class Solution {
public:
    int ans=0;
     int sol(TreeNode* root)
    {
        if(root==NULL) return 1;
        int left=sol(root->left);
        int right=sol(root->right);
        if(left==-1||right==-1)
        {
            ans++;
            return 0;
        }
        if(left==0||right==0) return 1;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(sol(root)==-1)
            ans++;
        return ans;
    }
};