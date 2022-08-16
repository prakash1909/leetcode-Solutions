class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> ele;
        for(int i=0;i<s.size();i++)
        {
            ele[s[i]]++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(ele[s[i]]==1)
            {
                return i;
            }
        }
        return -1;
    }
};