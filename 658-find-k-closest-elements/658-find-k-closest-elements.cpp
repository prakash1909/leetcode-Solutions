class Solution {
public:
     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        for(auto itr=arr.begin();itr!=arr.end();itr++) *itr-=x;
        sort(arr.begin(),arr.end(),[](int a, int b){return (a==-1*b && a<b) ? 1:abs(a)<abs(b);});
        for(int i=0;i<k;i++) result.push_back(arr[i]);
        for(auto itr=result.begin();itr!=result.end();itr++) *itr+=x;
        sort(result.begin(),result.end());
        return result;
    }
};