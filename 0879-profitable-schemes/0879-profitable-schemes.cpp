class Solution {
public:
    int dp[102][102][102];
    long mod=1e9+7;
    int solve(int idx, int len, int n, int miPro, vector<int> &gr, vector<int> &pro, int curr_pro){
        if(idx==len){
            if(curr_pro==miPro){
                return 1;
            }
            return 0;
        }

        if(dp[idx][n][curr_pro]!=-1){
            return dp[idx][n][curr_pro];
        }

        long ans=0;
        if(n>=gr[idx]){
            ans=(ans+solve(idx+1,len,n-gr[idx],miPro,gr,pro,min(curr_pro+pro[idx],miPro)))%mod;
        }
        ans=(ans+solve(idx+1,len,n,miPro,gr,pro,curr_pro))%mod;

        return dp[idx][n][curr_pro] = ans%mod;
    }

    int profitableSchemes(int n, int miPro, vector<int>& gr, vector<int>& pro) {
        memset(dp,-1,sizeof(dp));
        return solve(0,gr.size(),n,miPro,gr,pro,0);
    }
};