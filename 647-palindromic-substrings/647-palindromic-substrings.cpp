class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int count=0;
        for(int g=0;g<dp.size();g++){
            // gap g represents each diagonal, all diagonal will start from first row and g column and end in last column only
            for(int i=0, j=g; j<dp.size(); i++, j++){
                if(g==0){
                    // base case on diagonal of matrix, string length is 1;
                    dp[i][j]=true;
                }
                else if(g==1){
                    //second base case when, string length is 2;
                    dp[i][j]=(s[i]==s[j]);
                }
                else{
                    dp[i][j]=((s[i]==s[j]) && dp[i+1][j-1]);
                }
                count=(dp[i][j])? count+1:count;
            }
        }
        return count;
    }
    
};