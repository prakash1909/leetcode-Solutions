class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word, ans = "";
        while(iss >> word){
            reverse(word.begin(), word.end());
            ans += word;
            ans += " ";
        }
        return ans.substr(0, ans.size() - 1);
    }
};