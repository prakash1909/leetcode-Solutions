class Solution {
public:
    
    int romanToInt(string s) {
        unordered_map<char, int> map;
        map['I']=1;
        map['V']=5;
        map['X']=10;
        map['L']=50;
        map['C']=100;
        map['D']=500;
        map['M']=1000;
        
        int idx = s.length()-1,nums=0;
        while(idx >= 0){
            if((idx > 0 && s[idx-1] == 'I') && (s[idx] == 'V' || s[idx] == 'X')){
                nums += (map[s[idx]] - map[s[idx-1]]);
                idx--;
            }else if((idx > 0 && s[idx-1] == 'X') && (s[idx] == 'L' || s[idx] == 'C')){
                nums += (map[s[idx]] - map[s[idx-1]]);
                idx--;
            }else if((idx > 0 && s[idx-1] == 'C') && (s[idx] == 'D' || s[idx] == 'M')){
                nums += (map[s[idx]] - map[s[idx-1]]);
                idx--;
            }else{
                nums += map[s[idx]];
            }
            idx--;
        }
        return nums;
    }
};