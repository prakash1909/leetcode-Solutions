class Solution {
public:
    bool isPowerOfFour(int n) {
    double temp = n;
    
    if(n<=0)
        return false;
    
    while(temp>1)
    {
        if(n%4!=0)
            return false;
        
        temp = (float)temp/4.0;
        n = n/4;
    }
    
    return true;
}
};