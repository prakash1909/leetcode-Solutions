class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        int res = 0;
        int l = 0,r=0;
        vector<int> mp(256,-1);

        while(r<n){

            if(mp[s[r]] != -1){
                l = max(mp[s[r]] + 1, l);
            }

            mp[s[r]] = r;

            res = max(res,r-l+1);
            r++;
        }
        return res;
    }
};