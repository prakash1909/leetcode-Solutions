class Solution {
public:
    int longestValidParentheses(string s) {
        string st;
        int ans=0;
        unordered_map<string,int> m;
        m[""]=-1;
        for(int i=0;i<s.size();++i)
        {
            if(st.empty())
            {
                m.clear();
                m[""]=-1;
            }
            if(!st.empty() and s[i]==')' and st.back()=='(')
            {
                st.pop_back();
                if(m.count(st))
                    ans=max(ans,i-m[st]);
                else
                    m[st]=i;               
            }
            else
            {
                st.push_back(s[i]);
                m[st]=i;                
            }
        }
        return ans;
    }
};