class Solution {
public:
    int mod = 1e9+7;
    int countOrders(int n) {
        
        long long res = 1;
        if(n == 1) return res;
        
        for(int i = 2; i<=n; i++){
            int spaces = 2*(i-1) + 1;
            int perm = spaces*(spaces+1)/2;
            res *= perm;
            res %= mod;
        }
        
        return res;
    }
};