class Solution {
public:
    
    unordered_map<string, pair<int, long>> records;
    vector<int> movesToStamp(string stamp, string target) {
        
        int n = target.size();
        int sliding = stamp.size();
        int prefix_sum = 0;
        for (int i = 0; i < n; i++){
            prefix_sum += target[i] - '0';
        }
        long available_steps = helper(stamp, sliding, target, n, prefix_sum, 0);
        // printf("available_steps=%d\n", available_steps);
        if (available_steps == INT_MAX){
            return {};
        }
        // according to the hashmap, recover the array.
        vector<int> result(available_steps);
        for (int i = 0; i < available_steps; i++){
            int index = this->records[target].first;
            result[available_steps - i - 1] = index;
            
            int start = index;
            int back = start + sliding - 1;
            for (int j = start; j <= back; j++){
                target[j] = '0';
            }
        }
        return result;
    }
    long helper(string& stamp, int sliding, string& target, int n, int prefix_sum, int lvl){
        
        if (prefix_sum == 0){
            return 0;
        }
        if (this->records.count(target) == 1){
            return this->records[target].second;
        }
        
        string temp(sliding, '*');
        long sub, result = INT_MAX;
        int best_index = -1;
        
        vector<pair<int, int>> pairs;
        for (int start = 0; start <= n - sliding; start++){
            int back = start + sliding - 1;
            //[start, back]
            
            bool satisfied = true;
            int degree = sliding;
            for (int i = start; i <= back; i++){
                if (target[i] != '0' && target[i] != stamp[i - start]){
                    satisfied = false;
                    break;
                }
                if (target[i] == '0'){
                    degree--;
                }
            }
            if (!satisfied || degree == 0){
                continue;
            }
            // greedy idea, it the codes go to here, then we find a possible solution
            int bak_prefix_sum = prefix_sum;
            for (int i = start; i <= back; i++){
                prefix_sum -= target[i] - '0';
                temp[i - start] = target[i];
                target[i] = '0';
            }
            sub = 1 + helper(stamp, sliding, target, n, prefix_sum, lvl + 1);
            for (int i = start; i <= back; i++){
                target[i] = temp[i - start];
            }
            prefix_sum = bak_prefix_sum;
            if (lvl + sub <= n * 10){
                best_index = start;
                result = sub;
                break;
            }
            break;
        }

        this->records.insert({target, {best_index, result}});
        return result;
    }
};