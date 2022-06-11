class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int>pref(n,0),post(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=nums[i]+pref[i-1];
        }
        post[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            post[i]=nums[i]+post[i+1];
        }
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[post[i]]=i;
        }
        sort(post.begin(),post.end());
        if(pref[n-1]<x && post[n-1]<x) return -1;
        // for(int i=0;i<n;i++) cout<<pref[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<post[i]<<" ";
        // cout<<endl;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int find=x-pref[i];
            int ind=lower_bound(post.begin(),post.end(),find)-post.begin();
            if(post[ind]==find){
                ans=min(ans,i+1+n-mp[find]);
            }
        }
        for(int i=0;i<n;i++){
            if(pref[i]==x){
                ans=min(ans,i+1);
            }
            if(post[i]==x){
                ans=min(ans,n-mp[post[i]]);
            }
        }
        if(ans==INT_MAX) ans=-1;
        return ans;
    }
};