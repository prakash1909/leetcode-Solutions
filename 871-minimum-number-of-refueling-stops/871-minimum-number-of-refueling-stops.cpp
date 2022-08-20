class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel>=target){
            return 0;
        }
        priority_queue<int>pq;
        int i=0, n=stations.size(),maxDist=startFuel,cnt=0;
        while(target>maxDist){
            while(i<n && stations[i][0]<=maxDist){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()){
                return -1;
            }
            maxDist+=pq.top();
            cnt++;
            pq.pop();
        }
        return cnt;
    }
};