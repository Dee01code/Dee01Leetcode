class Solution {
public:
    int dp[500005][4];
    
    int solve(vector<int>& obs, int ind, int lane) {
        if (ind >= obs.size()) {
            return 0;
        }
        
        if (dp[ind][lane] != -1) return dp[ind][lane];
        
        int ans = INT_MAX;
        if (ind + 1 >= obs.size() || obs[ind + 1] != lane) {
            ans = min(ans, solve(obs, ind + 1, lane));
        } else {
            for (int i = 1; i <= 3; i++) {
                if (obs[ind] != i && i != lane) {
                    ans = min(ans, 1 + solve(obs, ind + 1, i));
                }
            }
        }
        return dp[ind][lane] = ans;
    }
    
    int minSideJumps(vector<int>& obs) {
        memset(dp, -1, sizeof(dp));
        return solve(obs, 0, 2);
    }
};

// class Solution {
// public:
    
//     int dp[500005][4];
//     int solve(vector<int>& obs, int ind, int lane){
        
//         if(ind >= obs.size()){
//             return 0;
//         }
        
//         if(dp[ind][lane] != -1) return dp[ind][lane];
        
//         int ans = INT_MAX;
//         if(obs[ind+1] != lane){
//             ans = min(ans,solve(obs, ind+1, lane));
//         }
//         else{
            
//             for(int i = 1; i <= 3; i++){
//                 if(obs[ind] != i && i != lane){
//                     ans = min(ans, 1 + solve(obs, ind+1, i));
//                 }
//             }

//         }
//         return dp[ind][lane] = ans;
//     }
    
//     int minSideJumps(vector<int>& obs) {
//         memset(dp, -1, sizeof(dp));
//         return solve(obs,0,2);   
//     }
// };