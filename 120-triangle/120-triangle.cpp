class Solution {
public:
    int dp[205][205];
    int helper(vector<vector<int>>& triangle,int i=0,int j=0){
        if(i >= triangle.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int k1 = triangle[i][j] + helper(triangle,i+1,j);
        int k2 = INT_MAX;
        if(j < triangle[i].size()){
           k2 = triangle[i][j] + helper(triangle,i+1,j+1);
       }
        return dp[i][j] = min(k1,k2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
      memset(dp,-1,sizeof(dp));
      return helper(triangle);
    }
};