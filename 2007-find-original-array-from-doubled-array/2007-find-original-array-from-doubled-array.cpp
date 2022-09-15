class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> first;
        if (n%2!=0) return first;
        sort(changed.begin(),changed.end());
        int pos = 0;
        //vector<int> first,second;
        first.emplace_back(changed[0]);
        for(int i = 1;i<changed.size();++i){
            if (pos<first.size() && changed[i] == 2*first[pos]){
                pos++;
            }else{
                first.emplace_back(changed[i]);
            }
        }
        
        if (pos==first.size()&&pos==n/2) return first;
        first = {};
        return first;
    }
};