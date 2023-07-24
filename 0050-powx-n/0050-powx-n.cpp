class Solution {
public:
    
    double rec(double x, long long n){
        if(n == 1) return x;
        double sub = rec(x,n/2);
        if(n&1) return x *sub*sub;
        return sub*sub;
    }
    
    double myPow(double x, long long n) {
        if(n==0) return 1;
        double ans = rec(x,abs(n));
        if(n<0) return 1/ans;
        return ans;
    }
};