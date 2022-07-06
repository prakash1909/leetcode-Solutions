class Solution {
public:
    int fib(int n) {
        if(n<2) return n; // fib(0) = 0, fib(1) = 1;
        int cur = 1, prev1 = 1, prev2 = 0; // prev1 = fib(n-1), prev2 = fib(n-2)
        for(int i=2;i<=n;++i){
            cur = prev1 + prev2; // fib(n) = fib(n-1) + fib(n-2)
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }
};