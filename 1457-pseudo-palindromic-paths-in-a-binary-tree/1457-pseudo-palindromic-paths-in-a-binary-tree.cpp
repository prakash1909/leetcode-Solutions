class Solution {
	public:
		int pseudoPalindromicPaths (TreeNode* root) {
			vector<int> v(10);
			int res=0;
			function<void(TreeNode*)> recur=[&](TreeNode* root){
				if(!root) return;
				if(!root->left&&!root->right){
					v[root->val]++;
					int c=0;
					for(int i=1;i<10;i++) {
						if(v[i]%2) c++;
					}
					v[root->val]--;
					if(c<=1) res++;
					return;
				}
				v[root->val]++;
				recur(root->left);
				recur(root->right);
				v[root->val]--;
			};    
			recur(root);
			return res;
		}
	};