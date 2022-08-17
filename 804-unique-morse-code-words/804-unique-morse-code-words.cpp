class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string strs[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-", "-.--","--.."};
        vector<int> l(26), c2i(26, 0);
        for(int i = 0; i < 26; ++i) {
            l[i] = strs[i].length();
            for(int j = l[i] - 1; j >= 0; --j) {
                if(strs[i][j] == '-') c2i[i] |= (1 << (l[i] - 1 - j));
            }
        }
        vector<unordered_set<long long>> vs(50);
        int ans = 0;
        for(string& s : words) {
            long long h = 0, code_len = 0;
            for(int i = 0; i < s.length(); ++i) {
                code_len += l[s[i]-'a'];
                h = h << l[s[i]-'a'];
                h |= c2i[s[i]-'a'];
            }
            if(vs[code_len].find(h) == vs[code_len].end()) {
                ++ans;
                vs[code_len].insert(h);
            }
        }
        return ans;
    }
};