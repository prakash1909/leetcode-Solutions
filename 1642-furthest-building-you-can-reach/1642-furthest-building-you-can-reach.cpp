class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq; // we will use priority queue for mintaining the max diff so that the max difference heights can be overcomed by using a ladder
        int pos = heights.size()-1;
        for(int i = 0;i<heights.size()-1;i++) {
            int diff = heights[i+1] - heights[i];
            if(diff<0) continue;// if the current height is greatre than the nex height then simply contnue
            else{
                if(ladders>0) pq.push(-diff),ladders--;
                else if(!pq.empty() && diff>-pq.top()) {// as we are storing max diff in the priority queue so if the current diff is greater than the top of the  queue then the top is poped out because we cn easily overcome the top height by the bricks,
                    bricks +=pq.top();
                    pq.pop();
                    pq.push(-diff);
                }
                else bricks -=diff;// if the priority queue is already maintaining the max diff then simply we have no other choice but to use that much diff amount of brick 
            }
            if(bricks<0){
                pos = i;
                break;
            }
        }
        return pos;
    }
};