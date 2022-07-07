class Solution {
public:
    string a, b, c;
    int m, n, o;
    bool f(int i, int j, int k, vector<vector<int>> &dp){
        //if reached end of first string then check that concationation of second string equals the remaining e3d string
		if(i==m) return b.substr(j)==c.substr(k);
        
		//if reached end of second string then check that concationation of first string equals the remaining e3d string
		if(j==n) return a.substr(i)==c.substr(k);
		
		//if already calculated result then return that
        if(dp[i][j]!=-1) return dp[i][j];
		
		//calculate if not done start with false
        bool ans = false;
		
		//condition one
		// 1) char at 1st string matches the 3rd string then continue with first and third string with indices increased by one
		// 2) char at 2nd string matches the 3rd string then continue with second third string with indices increased by one
        if((c[k]==a[i] and f(i+1,j,k+1,dp)) or (b[j]==c[k] and f(i,j+1,k+1,dp))){
            ans=true;
        }
        return dp[i][j]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        m=s1.length(), n=s2.length(), o=s3.length();
        a=s1, b=s2, c=s3;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(0,0,0,dp);
    }
};