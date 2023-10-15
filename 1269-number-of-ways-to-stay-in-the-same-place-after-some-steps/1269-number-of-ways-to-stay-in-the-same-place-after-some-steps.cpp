#define mod 1000000007;
class Solution {
public:
    int dp[502][502];
    
    int solve(int len, int steps, int ind){
        if(ind < 1 || ind > len) return 0;
        if(steps == 0){
            if(ind == 1) return 1;
            return 0;
        }
        
        auto& it = dp[steps][ind];
        if(it != -1) return it;
        int ans = 0;
        int stay = solve(len, steps-1, ind);
        ans += stay;
        int left = solve(len, steps-1, ind-1)%mod;
        ans = (ans+left)%mod;
        int right = solve(len, steps-1, ind+1)%mod;
        ans = (ans+right)%mod;
        
        return it = ans;        
    }
    
    int numWays(int steps, int len) {
        memset(dp, -1, sizeof(dp));
        return solve(len,steps,1);
    }
};