class Solution {
public:
    vector<int> ans;
    void dfs(string temp,int n,int &k){
        if(n == 0) {ans.push_back(stoi(temp)); return;}
        if(temp.back() - k >= '0')  dfs(temp + char(temp.back() - k),n - 1,k);
        if(temp.back() + k <= '9' && k != 0)  dfs(temp + char(temp.back() + k),n - 1,k);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1;i<10;i++) dfs(string(1,i + '0'),n - 1,k);
        return ans;
    }
	};