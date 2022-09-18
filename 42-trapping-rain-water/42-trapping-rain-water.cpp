class Solution {
public:
    int trap(vector<int>& height) {
        int maxHeightIdx = -1;
        int maxHeight = -1;
        int n = height.size();
        for(int i=0; i<n; i++){
            if (height[i]>maxHeight){
                maxHeight = height[i];
                maxHeightIdx = i;
            }
        }
        int start = 0;
        int curSum = 0;
        int ans = 0;
        // Split array at max height
        for(int i=1; i<=maxHeightIdx; i++){
            if (height[i]>=height[start]){
                ans += (i-start-1)*min(height[start], height[i]) - curSum;
                curSum = 0;
                start = i;
            }else{
                curSum += height[i];
            }
        }
        int end = n-1;
        curSum = 0;
        for(int i= n-2; i>= maxHeightIdx; i--){
            if (height[i]>=height[end]){
                ans += (end-i-1)*min(height[i], height[end]) - curSum;
                curSum = 0;
                end = i;
            }else{
                curSum += height[i];
            }
        }
        return ans;
    }
};