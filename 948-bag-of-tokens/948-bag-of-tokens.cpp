class Solution {
public:
    int bagOfTokensScore(vector<int>& nums, int pow) 
    {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1,ans=0,ans1=0;
        while(i<=j)
        {
            if(pow>=nums[i])
            {
                pow-=nums[i];  //DECREASING POWER LEFT
                ans++;   //COUNTING POINT
                i++;        // LOWEST POWER TOKEN UPDATED
                ans1=max(ans1,ans);  //STORING THE MAXIMUM ANSWER
            }
            else if(ans>0)
            {
                pow+=nums[j];  // INCREASING POWER
                ans--;   // DECREASING POINTS
                j--;     // HIGHEST POWER TOKEN UPDATED
            }
            else
            {
                break;
            }
        }
        return ans1;
    }
};