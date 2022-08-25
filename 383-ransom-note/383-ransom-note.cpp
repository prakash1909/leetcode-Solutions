class Solution {
public:
    bool canConstruct(string a, string b) 
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());       
        int i,j=0;
        for(auto i : b)
        {
            if(i == a[j] && j < a.length()) j++;
        }
        return j>=a.length() ? 1 : 0;       
    }
};