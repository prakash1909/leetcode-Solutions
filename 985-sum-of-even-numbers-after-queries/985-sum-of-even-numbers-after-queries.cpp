class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        for(auto it:nums)
        {
            if(it%2==0)
                sum+=it;
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            auto it=queries[i];
            int x=nums[it[1]];
            if(x%2==0)
            {
                sum-=x;
            }
            nums[it[1]]+=it[0];
            if(nums[it[1]]%2==0)
                sum+=nums[it[1]];
            ans.push_back(sum);
        }
        return ans;
    }
};