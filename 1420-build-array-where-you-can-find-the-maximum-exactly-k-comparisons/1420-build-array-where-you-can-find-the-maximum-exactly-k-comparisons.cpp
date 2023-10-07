class Solution {
public:
    
    int N,M,K, Mod = 1e9+7;
    int dp[51][101][51];
    
    int solve(int ind, int maxi, int srch){
        if(ind >= N){
            if(srch == K) return 1;
            return 0;
        }
        auto &ans = dp[ind][maxi][srch];
        if(ans != -1) return ans;
        
        int result = 0;
        
        for(int i = 1; i<=M; i++){
            if(i > maxi){
                result = (result + solve(ind+1, i, srch+1))%Mod;
            }
            else{
                result = (result + solve(ind+1, maxi, srch))%Mod;
            }
        }
        return ans = result%Mod;
    }
    
    int numOfArrays(int n, int m, int k) {
        N = n; M= m; K = k;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
};