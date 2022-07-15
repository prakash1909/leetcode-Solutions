class Solution {
public:
	
	int solve(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis){
		if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j]==1) return 0;
		
		if(grid[i][j]==0) return 0;
		
		vis[i][j] = 1;
		return 1 + solve(i-1,j,grid,vis) + solve(i+1,j,grid,vis) + solve(i,j+1,grid,vis) + solve(i,j-1,grid,vis);
	}
	
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int res = 0;
		vector<vector<bool>> vis(m,vector<bool>(n,0));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j]==1 && vis[i][j]==0){
					res = max(res,solve(i,j,grid,vis));
				}
			}
		}
		return res;
	}
};