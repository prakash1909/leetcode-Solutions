class Solution {
public:
    bool isPossible(vector<int>& target) {
        typedef long long ll;
		//edge case since we'll be looking at 2nd largest element, if there is None we error
		// so we just check if the size == 1 and if it is just check if its 1 otherwise it cant grow 
		// so it has to be invalid
        if(target.size() == 1) return target[0] == 1;
        priority_queue<int> pq;
        ll total = 0;
        for(int i = 0;i < target.size();++i){
            total += target[i];
            pq.push(target[i]);
        }
        while(true){
            int t = pq.top();
            
            if(t == 1) return true;
            pq.pop();
            
            //second largest
            int sl = pq.top();
            
            //since 2 elements cant be equal if its not 1
            if(sl == t) return false;
            int l = 0, h = 1e5;
            
            while(l <= h){
                int m = l+(h-l)/2;
                ll x = (ll)(m+1)*(ll)t-(ll)m*(ll)total;
                if(x <= sl) h = m-1;
                else l = m+1;
            }
            
            // top = (l+1)* top - l*total
            // total = l * top - (l-1)*total
            
            ll newt = (ll)(l+1)*(ll)t-(ll)l*(ll)total;
            ll newtotal = (ll)l*(ll)t-(ll)(l-1)*(ll)total;
            t = newt;
            total = newtotal;
            
            if(t <= 0) return false;
            if(total == 0) return false;
            
            pq.push(t);
        }
        return false;
    }
};