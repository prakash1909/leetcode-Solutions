class Solution {
    vector<vector<vector<int>>> dp;
    pair<int,int> count(string &s){
        int one=0,zero=0;
        for(auto x:s){
            x=='0'?zero++:one++;
        }
        return {zero,one};
    }
    vector<pair<int,int>> hash;
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();int mm = m; int nn = n;
        dp.resize(len+1, vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(auto x:strs){
            hash.push_back(count(x));
        }
        for(int i=0; i<=len; i++){
            for(int j=0; j<=m; j++){
                for(int k=0; k<=n;k++){
                    if(i==0){
                        dp[i][j][k] = 0;
                        continue;
                    }
                    auto p = hash[i-1];
                    if(p.first<=j && p.second<=k){
                        dp[i][j][k] = max(1+dp[i-1][j-p.first][k-p.second],dp[i-1][j][k]);
                    }
                    else{
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        
        return dp[len][m][n];
    }
};