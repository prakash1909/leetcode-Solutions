class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        map<int, vector<pair<int, int>>> table;
        q.push(make_pair(root, 0));
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();
                table[curr.second].push_back({level, curr.first->val});
                if(curr.first->left){
                    q.push(make_pair(curr.first->left, curr.second-1));
                }
                if(curr.first->right){
                    q.push(make_pair(curr.first->right, curr.second+1));
                }
            }
            level++;
        }
        vector<vector<int>> ans;
        for(auto iter=table.begin(); iter!=table.end();iter++){
            auto temp = iter->second;
            sort(temp.begin(), temp.end(), [](auto& a, auto& b){
                if (a.first < b.first){
                    return true;
                }
                else if (a.first == b.first && a.second < b.second){
                    return true;
                }
                else{
                    return false;
                }
            });
            vector<int> val;
            for(auto p: temp){
                // cout<<p.first<<" "<<p.second<<endl;
                val.push_back(p.second);
            }
            ans.push_back(val);
        }
        return ans;
    }
};