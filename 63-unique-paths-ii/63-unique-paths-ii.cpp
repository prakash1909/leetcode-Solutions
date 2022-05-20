class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int row=og.size();
        int col=og[0].size();
        if(og[0][0]==1||og[row-1][col-1]==1) return 0;
        vector<vector<int>> res(row,vector<int> (col,-1));
        return helper(og,0,0,res);
        
    }
    int helper(vector<vector<int>>& og,int i,int j,vector<vector<int>>& dp)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==og.size()-1&&j==og[0].size()-1)
        {
           return dp[i][j]=1;
        }
        int down=0,right=0;
        if(og[i][j]==1)
        {
            return dp[i][j]=0;
        }
        if(j<og[0].size()-1) //down cell
        {
            if(dp[i][j+1]!=-1)   down=dp[i][j+1];
            else
            {
                down=helper(og,i,j+1,dp);
            }
                
        }
        if(i<og.size()-1)  //right cell
        {
            if(dp[i+1][j]!=-1)
                right=dp[i+1][j];
            else
                right=helper(og,i+1,j,dp);
        }
        return dp[i][j]=(down+right);
    }
};