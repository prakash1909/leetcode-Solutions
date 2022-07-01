class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>>pq;
        int sum =0;
        for(vector<int>x:boxTypes){
            pq.push({x[1],x[0]});
        }
            
            int units=0;
            while(!pq.empty() && sum<truckSize){
                if(sum+pq.top().second<truckSize){
                    sum+=pq.top().second;
                    units+=pq.top().second*pq.top().first;
                    pq.pop();
                }
                else{
                    int quantity=truckSize-sum;
                    sum+=quantity;
                    units+=quantity*pq.top().first;
                    pq.pop();
                }
                    
            }
        
        return units;
        
    }
};