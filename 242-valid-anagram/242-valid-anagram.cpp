class Solution 
{
    public:
    bool isAnagram(string s, string t) {
        multiset<char> m1(s.begin(), s.end());
        multiset<char> m2(t.begin(), t.end());
        
        return m1 == m2;
    }
};