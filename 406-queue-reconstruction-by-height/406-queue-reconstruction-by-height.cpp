class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // greedily add the ones with lowest before val, lowest val
        // take min val with 0 before, add it to ans
        // do a bfs, visited, subtract before val, if zero, add to min_heap (in inc order of val)
        // have a rem array - to show rem before val
        int n = people.size();
        vector<vector<int>> ans;
        int max_val = INT_MAX, max_ind;
        vector<int> vis(n, 0);
        vector<int> before;
        for(auto x : people)
            before.push_back(x[1]);
        for(int i = 0; i<n;i++){
            auto p = people[i];
            if(p[1] == 0 && p[0] > max_val){
                max_val = p[0];
                max_ind = i;
            }
            if(p[1] == 0){
                before[i] = 0;
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            if(before[i]==0){
                int a = people[i][0], b = people[i][1];
                pq.push({a, b});
                vis[i] = true;
            }
        }
        // cout<<pq.size()<<endl;
        while(pq.size()){
            auto pp = pq.top(); pq.pop();
            ans.push_back({pp.first, pp.second});
            
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    if(pp.first >= people[i][0]){
                        before[i]--;
                    }
                    if(!before[i]){
                        pq.push({people[i][0], people[i][1]});
                        vis[i] = true;
                    }
                }
            }
        }
        
        return ans;
    }
};