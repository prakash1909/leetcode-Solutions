class Solution {
public:
   bool isPowerOfThree(int n) {

    if(n==0)
        return 0;
    
    while(n!=1){
        
        if(n%3==0)
            n/=3;
        else 
            return 0;
    }
    
    return 1;
}};