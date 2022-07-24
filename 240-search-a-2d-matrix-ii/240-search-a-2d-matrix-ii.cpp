class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int r=0;
        int c=v[0].size()-1;//start from right corner
        while(r>-1 && r<v.size() && c>=0 && c<v[0].size())
        {
            if(v[r][c]==target)
            {
                return true;
            }
            else if(v[r][c]<target)
            {
                r++;
            }
            else
            {
                c--;
            }
        }
        return false;
    }
};